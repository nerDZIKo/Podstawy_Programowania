import pprint

# #Zadanie 1
print("Hello, World!")

# #Zadanie 2
print("Podaj dwie liczby!")
first_number = int(input("Podaj Pierwszą: "))
second_number = int(input("Podaj Drugą: "))
print("----------------")
print(first_number)
print(second_number)

print(first_number + second_number)
print(first_number - second_number)
print(first_number / second_number)
print(first_number * second_number)

# #Zadanie 3
number = int(input("Podaj liczbę do sprawdzenia: "))
if number > 0:
    print("Liczba dodatnia")
elif number < 0:
    print("Liczba ujemna")
else:
    print("Liczba zero")

# Zadanie 4
for i in range(10):
    print(i + 1)
number = 20
while number < 41:
    print(number)
    number = number + 1

# Zadanie 5
list_of_names = ["Kuba", "Jakub", "Bartek"]
for name in list_of_names:
    print(name)


# Zadanie 6
def sum_of_numbers(number_1, number_2):
    sum = number_1 + number_2
    return sum


print(sum_of_numbers(1, 20))


# Zadanie 7
def reverse_word(word):
    word[::-1]
    if (
        len(word) <= 1
    ):  # Jeżeli długość znaków jest zmniejsza równa 1 -> zwróć słowo - w sumie literę lub jej brak
        return word
    return reverse_word(word[1:]) + word[0]  # A jak nie, to używamy rekurencji (W jednej linijce można)


print(reverse_word("Kota ma Ala"))

# Zadanie 8
lista = list(range(1, 11))
print(lista)



# Zadanie 9
user_input = input("Podaj liczbę")
try:
    user_input = int(user_input)
    print("Liczba ok")
except:
    print("Podano liczę niecałkowitą albo coś innego")

# Zadanie 10
pair_of_keys = {"imiona": ["Jakub", "Magdalena"], "lata": ["18", "23"]}

for name in pair_of_keys["imiona"]:
    print(name)
for age in pair_of_keys["lata"]:
    print(age)

print(pair_of_keys)

# Zadanie 11

# Write mode: Creates a new file or truncates an existing file
with open("file.txt", "w") as f:
    f.write("Created using write mode.")

f = open("file.txt", "r")
print(f.read())
f.close() 
