# Klasa nadrzędna (bazowa)
class Osoba:
    """
    Atrybuty:
    - imie
    - wiek
    
    Metody:
    - funkcja: opisz()
    """
    def __init__(self, imie, wiek):
        self.imie = imie
        self.wiek = wiek
    
    def opisz(self):
        print(self.imie + ", " + str(self.wiek) + " lat.")

osobnik_numer_33 = Osoba("Jasiek", 7)

print(osobnik_numer_33.imie)
print(osobnik_numer_33.wiek)

# Klasa podrzędna (dziedzicząca po Osoba)
class Student(Osoba):
    def __init__(self, imie, wiek, numer_indeksu):
        super().__init__(imie, wiek)  # Wywołanie konstruktora klasy nadrzędnej
        self.numer_indeksu = numer_indeksu
    
    def opisz(self):
        super().opisz()  # Wywołanie opisz() z klasy Osoba
        print("Numer indeksu: " + str(self.numer_indeksu))

student_1 = Student("Jakub", 21, 33335)
student_1.opisz()
