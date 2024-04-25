Tutorial
==================
Usaré la editorial oficial de los problemas. Solo incluiré algunos comentarios extras en algunos donde no sea tan clara la explicación. 


A. Division
------------------

<spoiler summary="Tutorial">
For this problem you just need to implement what it asks you. To be able to implement it you need to know about the "if" statement.
</spoiler>

<spoiler summary="Code">
```c++
#include "bits/stdc++.h"
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        if(x < 1400) cout << "Division 4\n";
        else if(x < 1600) cout << "Division 3\n";
        else if(x < 1900) cout << "Division 2\n";
        else cout << "Division 1\n";
    }
}
```
</spoiler>


B. Sum of Round Numbers
------------------

<spoiler summary="Tutorial">
Firstly, we need to understand the minimum amount of round numbers we need to represent $n$. It equals the number of non-zero digits in $n$. Why? Because we can "remove" exactly one non-zero digit in $n$ using exactly one round number (so we need at most this amount of round numbers) and, on the other hand, the sum of two round numbers has at most two non-zero digits (the sum of three round numbers has at most three non-zero digits and so on) so this is useless to try to remove more than one digit using the sum of several round numbers.

So we need to find all digits of $n$ and print the required number for each of these digits. For example, if $n$=103, then $n$=$1⋅10^2+0⋅10^1+3⋅10^0$, so we need two round numbers: $1⋅10^2$ and $3⋅10^0$.

To code this, we can use the fact that the last digit of $n$ is $n%10$ (the remainder of $n$ when divided by $10$) and we can remove the last digit of the number by integer division on $10$.
</spoiler>

<spoiler summary="Code">
#include <bits/stdc++.h>

using namespace std;
```c++
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ans;
		int power = 1;
		while (n > 0) {
			if (n % 10 > 0) {
				ans.push_back((n % 10) * power);
			}
			n /= 10;
			power *= 10;
		}
		cout << ans.size() << endl;
		for (int number : ans) 
                	cout << number << " ";
		cout << endl;
	}
}
```
</spoiler>

C. Easy As ABC
------------------
<spoiler summary="Tutorial">
La idea de este problema es que recuerden el poder de la solución bruta. El tamaño de la matriz es muy pequeño, por lo que pueden permitirse muchas cosas. 

Así, pueden literalmente considerar todas las tripletas de celdas y checar que sean distintas y adyacentes. Si esto se cumple, consideran tal tripleta y guardan la cadena mínima de las tripletas válidas. 

Para considerar todas las posibilidades para una sola celda, se pueden usar dos fors para recorrer toda la matriz. Esto es un recorrido $O(N^2)$ para una sola celda, con $N=3$. 

Para considerar todas las tripletas de celdas, necesitan considerar todas las posibilidades para la primera celda, todas las posibilidades para la segunda celda y todas las posibilidades para la tercera. Esto da una complejidad total de $O(N^6)$. Como $N^6<10^8$, esta complejidad es suficiente para resolver el problema. (Recuerden que aproximadamente se pueden realizar $10^8$ operaciones por segundo). 
</spoiler>
<spoiler summary="Code">
```c++
//Puse nombres de variables super largos para que sea mas clara la lectura. Pero, normalmente es mejor (al menos en programacion competitiva) usar nombres mas cortos. Ademas, hay menos probabilidades de errores al teclear. 
#include <iostream>
#include <vector>
using namespace std;
 
bool sonDiferentes(int f1, int c1, int f2, int c2){
    return !(f1 == f2 && c1 ==c2);
}

bool sonAdyacentes(int f1, int c1, int f2, int c2){
    return abs(f1-f2)<=1 && abs(c1-c2)<=1;
}

int main() {
    string s;
    string resp = "CCC"; // la respuesta mas grande que se puede tener
    char m[3][3];

    // leemos la matriz
    for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){ 
        cin>>m[i][j];
    }
    }
 
    for(int filaCelda1=0; filaCelda1<3; filaCelda1++)
    for(int columnaCelda1=0; columnaCelda1<3; columnaCelda1++)
        for(int filaCelda2=0; filaCelda2<3; filaCelda2++)
        for(int columnaCelda2=0; columnaCelda2<3; columnaCelda1++)
            for(int filaCelda3=0; filaCelda3<3; filaCelda3++)
            for(int columnaCelda3=0; columnaCelda3<3; columnaCelda3++)
                if(sonDiferentes(filaCelda1, columnaCelda1, filaCelda2, columnaCelda2) 
                    and sonDiferentes(filaCelda1, columnaCelda1, filaCelda3, columnaCelda3)          
                    and sonDiferentes(filaCelda2, columnaCelda2, filaCelda3, columnaCelda3)
                    and sonAdyacentes(filaCelda1, columnaCelda1, filaCelda2, columnaCelda2)
                    and sonAdyacentes(filaCelda2, columnaCelda2, filaCelda3, columnaCelda3))
                {
                    s = "";
                    s += m[filaCelda1][columnaCelda1];
                    s += m[filaCelda2][columnaCelda2];
                    s += m[filaCelda3][columnaCelda3];
                    resp = min(resp, s);
                }
    cout<<resp<<"\n";
}
```
</spoiler>


D.Yet Another Coin Problem
------------------
<spoiler summary="Solution 1">
Fact: You will never need more than $2$ ones, $1$ threes, $4$ sixes and $2$ tens.

Reason:
For $1$: Suppose you used $k>2$ ones, then you could have used one $3$ and $k-3$ ones.
For $3$: Suppose you used $k>1$ threes, then you could have used one $6$ and $k-2$ threes.
For $6$: Suppose you used $k>4$ sixes, then you could have used two $15$'s and $k-5% sixes.
For $10$: Suppose you used $k>2$ tens, then you could have used two $15$'s and $k-3$ tens.

Now since bound on their count is less, we can bruteforce on these count.
</spoiler>
<spoiler summary="Code">
```c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int t = 1; t <= testcases; t++)
    {
        int n;
        cin >> n;
        int ans = 1e9; // setting an upper bound for the answer
        for(int ones = 0; ones <= 2; ones++){
            for(int threes = 0; threes <= 1; threes++){
                for(int sixes = 0; sixes <= 4; sixes++){
                    for(int tens = 0; tens <= 2; tens++){
                        int brute_sum = 1*ones + 3*threes + 6*sixes + 10*tens;
                        if(brute_sum <= n && (n-brute_sum)%15 == 0){
                            ans = min(ans, ones + threes + sixes + tens + (n-brute_sum)/15);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
```
</spoiler>
<spoiler summary="Solution 2">
Fact 1: If coins of value $1$, $3$, $6$ and $15$ were only present the greedy logic of selecting the higher valued first would work.

Reason: We use coins of value one at most 2 times, coins of value three at most 1 time, coins of value six at most 2 times (if it was used 3 times, it would be better to use two coins 15+ one coin of 3). But we can't use the coin of value 3 and both coins of value $6$ simultaneously, because we would prefer just using 15.

It means that these coins may sum up to $1+1+3+6=11$ or $1+1+6+6=14$ at max. So, we may use the value $15$ greedily, because the remaining part is less than $15$. When we are left with only the values $1$, $3$, and $6$, greedily solving is obviously correct, because each coin is a divisor of the next coin.

Fact $2$: We don't need more than $2$ ten coins.
Reason: Better to use $2$ fifteen coins instead of $3$ ten coins.

Using the above two facts it can be shown that the answer will have $k<3$ ten coin. Therefore, answer = min(answer$(n−10∗k)+k$) over the values of $0<=k<3$, and assuming 1, 3, 6 and 15 are the only coins present.
</spoiler>
<spoiler summary="Code">
```c++
#include<bits/stdc++.h>
 
using namespace std;
 
int getAns(int n){
    int ans=0;
    ans+=n/15;
    n%=15;
    ans+=n/6;
    n%=6;
    ans+=n/3;
    n%=3;
    ans+=n;
    return ans;
}
 
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int testcases;
    cin>>testcases;
    for(int i=1;i<=testcases;i++){
        int n;cin>>n;
        if(n<10){
            cout<<getAns(n)<<endl;
        }else if(n<20){
            cout<<min(getAns(n),getAns(n-10)+1)<<endl;
        }else{
            cout<<min({getAns(n),getAns(n-10)+1,getAns(n-20)+2})<<endl;
        }
    }
}
```
</spoiler>

E. Eat the Chip
------------------
<spoiler summary="Tutorial">
First, let's note that the difference $x_b-x_a$ decreases exactly by one each (both Alice's and Bob's) turn. In the end, if one of the players was able to win, $x_b-x_a$=0. In particular, that means that if $x_a-x_b$ is initially odd then only Alice has a chance of winning the match and if is even then only Bob has a chance of winning.

Suppose that $x_a-x_b$ is initially even (the outcome of the match could be either Bob's win or draw). If $x_a \geq x_b$ the answer is immediately draw. Otherwise, the players will make $t=(x_b-x_a)/2$ moves each before $x_a=x_b%.

If at some point during these $2t$ moves Bob can achieve $y_a=y_b$, he is winning as he can continue with symmetrical responses to Alice's turns.

If $y_a > $y_b%$ and Bob cannot reach right border $(w>y_b+t)$, Alice can always choose the rightmost option for her and after each of $2t$ moves $y_a$ will be greater than $y_b$ which means Bob cannot win. Otherwise, if Bob always chooses the rightmost option for him, he will eventually achieve $y_a=y_b$.

The case when $y_a$ is initially less than $y_b$ as well as the case when Alice has a chance to win ($x_b-x_a$ is odd) can be covered in a similar way.
</spoiler>
<spoiler summary="Code">
```python3
def solve():
    h, w, xA, yA, xB, yB = map(int, input().split())

    if (xA - xB) % 2 == 0:
        winner = "Bob"
        if xA >= xB:
            win = False
        elif yA == yB:
            win = True
        else:
            if yA < yB:
                n_turns = yB - 1
            else:
                n_turns = w - yB
            win = xB - 2 * n_turns >= xA

    else:
        winner = "Alice"

        xA += 1
        yA += 0 if yB - yA == 0 else 1 if yB - yA > 0 else -1

        if xA > xB:
            win = False
        elif yA == yB:
            win = True
        else:
            if yA < yB:
                n_turns = w - yA
            else:
                n_turns = yA - 1
            win = xB - 2 * n_turns >= xA

    print(winner if win else "Draw")


t = int(input())

for _ in range(t):
    solve()
```
</spoiler>

F. Accumulator Apex
------------------
<spoiler summary="Tutorial">
Let us break each list of integers into sublists greedily: 1) we go over elements maintaining their sum and
the minimum sum seen so far; 2) when the sum becomes positive we split the list and store the sum and
the minimum observed sum; and 3) we continue with the list from the step $1$ until it becomes empty.
Then, we populate the priority queue with the first lists of each list sorted by the minimum observed
sum. Now, we should take the sublist with the biggest minimum sum (the less negative) as it reduces the chances to make
$x$ non-negative while increasing it, at the end. Thus, in each step, we take the sublist with the biggest
minimum and apply it to $x$. Then, we withdraw this sublist from the corresponding list $i$ and put the
next sublist from the list $i$ into the priority queue.
</spoiler>
<spoiler summary="Code">
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
typedef pair<ll,ll> pl;

const int maxN = 500005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    ll x, k; cin>>x>>k;
    queue<pl> lists[k];
    loop(i, 0, k){
        int n; cin>>n;
        ll sum = 0, num, cost = 0;
        loop(j, 0, n){
            cin>>num;
            sum += num;
            cost = max(cost, -sum);
            if(sum > 0){
                lists[i].push(pl(cost, sum));
                sum = cost = 0;
            }
        }
    }

    priority_queue<pl, vector<pl>, greater<pl> > minHeap;
    loop(i, 0, k){
        if(!lists[i].empty())
            minHeap.push(pl(lists[i].front().first, i));
    }

    int listIndx;
    while(!minHeap.empty() && x >= minHeap.top().first){
        listIndx = minHeap.top().second;
        x += lists[listIndx].front().second;
        minHeap.pop();
        lists[listIndx].pop();

        if(!lists[listIndx].empty())
            minHeap.push(pl(lists[listIndx].front().first, listIndx));
    }
    cout<<x<<"\n";
    return 0;
}
```
</spoiler>

G. Completely Searching for Inversions
------------------
<spoiler summary="Tutorial">
Note that during the entire process, each time we do $dfs(x)$ for the same value of $x$, the sequence of values appended to the end of $Z$
 is always the same. So, for each vertex $x$
, we want to obtain some properties about the sequence of values that will be appended if we do $dfs(x)$. Since we want to calculate the number of inversions in a sequence of $0$ and $1$ elements, for each $x$, we want to calculate:

<ul>
 <li> $f_0[x]$: the number of $0$ elements appended. </li>
<li>$f_1[x]$: the number of $1$ elements appended. </li>
<li>$inv[x]$: the number of inversions completely within the sequence appended </li>
</ul>

Then, we can solve the problem using dynamic programming on directed acyclic graph. For a vertex $x$
, we iterate each vertex $y$
 that it is directed towards (following the order given in the input). If the integer in the current edge is $w$
, then we temporarily add $f_w[y]$ by $1$ and if $w$=1
, then we temporarily add inv[𝑦]
 by $f_0[y]$. Then, we do the following transitions:

<ul>
<li> Add $inv[x]$ by $inv[y]+f_1(x)•f_0(y)$</li>
<li>Add f_0[x] by $f_0[y]$</li>
<li>Add $f_1[x]$ by $f_1[y]$</li>
</ul>
The answer is $inv[1]$.

Time complexity: $O(N+\sum S)$
</spoiler>
<spoiler summary="Code">
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 998244353
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pi;

const int maxN = 100005;
int n; 
bool visited[maxN];
vector<pi> adj[maxN];
ll inversions[maxN], ones[maxN], zeros[maxN];

void dfs(int u){
    visited[u] = true;
    ones[u] = zeros[u] = inversions[u] = 0;
    for(pi neighbor : adj[u]){
        int v = neighbor.first;
        int w = neighbor.second;
        if(w == 1)
            ones[u] = (ones[u] + 1)%MOD;
        else if(w == 0){
            zeros[u] = (zeros[u] + 1)%MOD;
            inversions[u] = (inversions[u] + ones[u])%MOD;
        }

        if(!visited[v])
            dfs(v);
        
        inversions[u] = (inversions[u] + inversions[v])%MOD;
        inversions[u] = (inversions[u] + ((zeros[v]*ones[u])%MOD) )%MOD;
        ones[u] = (ones[u] + ones[v])%MOD;
        zeros[u] = (zeros[u] + zeros[v])%MOD;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n;
    loop(i, 1, n+1){
        int s; cin>>s;
        loop(j, 0, s){
            int l, w;
            cin>>l>>w;
            adj[i].push_back(pi(l, w));
        }
    }

    dfs(1);
    cout<<inversions[1]<<"\n";

    return 0;
}
```
</spoiler>