# Implement the Euclidean Algorithm for integers and polynomials.

from sympy import symbols, div def
euclidean_algorithm_integers(a, b):
while b != 0:
a, b = b, a % b
return a
def euclidean_algorithm_polynomials(a, b, x):
while b != 0:
a, b = b, div(a, b, domain='QQ')[1]
return a
print("GCD of 270 and 192:", euclidean_algorithm_integers(270, 192))

x = symbols('x') a = 3*x**4 - 2*x**3 + 3*x**2 - 6*x + 2 b = 3*x**3 +
2*x**2 - 3*x - 2 print("GCD of two polynomials:",
euclidean_algorithm_polynomials(a, b, x))
