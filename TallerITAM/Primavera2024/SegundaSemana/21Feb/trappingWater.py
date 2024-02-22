# Problema: https://leetcode.com/problems/trapping-rain-water/description/
class Solution:
    def trap(self, height) -> int:
        n = len(height)
        # calcular maximo izquierda
        maximoIzquierda = [0]*n
        maximoIzquierda[0] = 0
        for i in range(1, n):
            maximoIzquierda[i] = max(height[i-1], maximoIzquierda[i-1])

        # calcular maximo derecha
        maximoDerecha = [0]*n
        maximoDerecha[n-1] = 0
        for i in range(n-2, 0, -1):
            maximoDerecha[i] = max(height[i+1], maximoDerecha[i+1])

        # calcular agua en cada uno y sumar todo 
        aguaTotal = 0
        for i in range(n):
            alturaLimite = min(maximoIzquierda[i], maximoDerecha[i])
            if alturaLimite > height[i]:
                aguaTotal += alturaLimite - height[i] 
        return aguaTotal