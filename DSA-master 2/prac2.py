def set_A():
    global setA 
    setA = set(())
    loop = True
    while loop:
        print("\n1.enter elements\n2.remove elements\n3.exit")
        choice = int(input("choice: "))
        if choice == 1:
            key = int(input("element: "))
            setA.add(key)
            print("============================")
        elif choice == 2:
            key = int(input("Enter element to be deleted: "))
            setA.discard(key)
            print("============================")
        elif choice == 3:
            loop = False
            print("============================")

def set_B():
    global setB 
    setB = set(())
    loop = True
    while loop:
        print("\n1.enter elements\n2.remove elements\n3.exit")
        choice = int(input("choice: "))
        if choice == 1:
            key = int(input("element: "))
            setB.add(key)
            print("============================")
        elif choice == 2:
            key = int(input("Enter element to be deleted: "))
            setB.discard(key)
            print("============================")
        elif choice == 3:
            loop = False
            print("============================")

def union():    
    setC = setA.union(setB)
    print("\nA Union B =", setC)
    print("============================")

def intersection():
    setD = setA.intersection(setB)
    print("\nA intersection B =", setD)
    print("============================")

def difference():
    setE = setA.difference(setB)
    print("\nA Difference B =", setE)
    print("============================")

def subset():
    print(setA.issubset(setB))
    print("============================")

def search():
    print("In which set u want to search\n1.Set A\n2.Set B ")
    choice = int(input("choice: "))
    key = int(input("enter key to be searched: "))
    if choice == 1:
        print(key in setA)
    else:
        print(key in setB)

def main():
    print("choose the operation")
    loop = True
    while loop:
        print("\n1.createsetA\n2.createsetB\n3.union\n4.Intersection\n5.difference\n6.subset\n7.search\n8.display\n9.exit")
        choice = int(input("choice: "))
        if choice == 1:
            set_A()
        elif choice == 2:
            set_B()
        elif choice == 3:
            union()
        elif choice == 4:
            intersection()
        elif choice == 5:
            difference()
        elif choice == 6:
            subset()
        elif choice == 7:
            search()
        elif choice == 8:
            print("\nset A =", setA)
            print("set B =", setB)
            print("============================")
        elif choice == 9:
            loop = False
main()