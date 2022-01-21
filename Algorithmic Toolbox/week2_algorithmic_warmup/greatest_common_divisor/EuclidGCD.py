## THIS IS MUCH FASTER ALGORITHMS, BUT IT NEEDS FROM US SOME STUDY ABOUT THE SUBJECTT AND SOME GCD PROPERETIES
#Each step reduces the size of numbers by about a factor of 2.
#Takes about log(ab) steps. ! ++ => WORKS FOR BIG BIG Numbers 

def EuclidGCD(a , b):
    if b == 0:
        return a
    else:
        a = a%b
        return EuclidGCD(b,a)


a = int(input())
b = int(input())

print(EuclidGCD(a,b))
