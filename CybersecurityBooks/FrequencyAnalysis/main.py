# leer el texto

# declarar objeto de frecuencias

# correr proceso que
# - lee el texto
# - deja solo las letras
# - cuenta frecuencias 
# - cada 100, guarda en una lista
# - cada que cambie el de mayor frecuencia, guarda la iteración en una tupla
# - cada que cambie el orden, guarda la iteración en una tupla
# - guarda en un archivo

alphabet = 'abcdefghijklmnopqrstuvwxyz'
class LetterFrequencyTracker:
    def __init__(self):
        self.frequencies = {x: 0 for x in alphabet} 
        self.history = []
        self.max_freq_changes = []
        self.order_changes = []
        self.last_max_freq_set = None
        self.last_order = None

    def process_text(self, text):
        for i, char in enumerate(text.lower()):
            if char in self.frequencies:
                self.frequencies[char] += 1
            
            if (i + 1) % 100 == 0:
                self.history.append(self.frequencies.copy())
                self.check_max_freq_change(i + 1)
                self.check_order_change(i + 1)

    def check_max_freq_change(self, iteration):
        current_max_freq = max(self.frequencies.values())
        current_max_set = (x for x in alphabet if self.frequencies[x] == current_max_freq)
        if current_max_set != self.last_max_freq_set:
            self.max_freq_changes.append((iteration, current_max_set))
            self.last_max_freq_set = current_max_set

    def check_order_change(self, iteration):
        current_order = tuple(sorted(self.frequencies.items(), key=lambda item: item[1], reverse=True))
        if current_order != self.last_order:
            self.order_changes.append((iteration, current_order))
            self.last_order = current_order

    def save_to_file(self, filename):
        with open(filename, 'w') as f:
            # f.write("Frequencies History:\n")
            # for i, freq in enumerate(self.history):
            #     sorted_freq = sorted(freq.items(), key=lambda item: item[1], reverse=True)
            #     freq_str = ', '.join([f"{letter}: {count}" for letter, count in sorted_freq])
            #     f.write(f"Iteration {i * 100 + 100}: {freq_str}\n")

            f.write("\nProbabilities History (rounded to 3 digits):\n")
            for i, freq in enumerate(self.history):
                total = sum(freq.values())
                sorted_freq = sorted(freq.items(), key=lambda item: item[1], reverse=True)
                prob_str = ', '.join([f"{letter}: {round(count/total, 2) if total > 0 else 0}" for letter, count in sorted_freq])
                f.write(f"Iteration {i * 100 + 100}: {prob_str}\n")

            f.write("\nMax Frequency Changes:\n")
            for change in self.max_freq_changes:
                f.write(f"Iteration {change[0]}: Max Frequency {change[1]}\n")
            f.write("\nOrder Changes:\n")
            for change in self.order_changes:
                f.write(f"Iteration {change[0]}: Order {change[1]}\n")

if __name__ == "__main__":
    tracker = LetterFrequencyTracker()
    
    with open("input.txt", "r") as file:
        text = file.read()
    
    tracker.process_text(text)
    tracker.save_to_file("output.txt")