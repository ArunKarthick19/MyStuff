import random

def game():
    print('Choose the game you want to play')
    print("1. Guessing game")
    print("2. Sum game")
    print("Type 1 or 2: ")
    option = int(input())
    if option == 1:
        import random
        n = random.randint(1,9)
        print('')
        print(n)
        guess = int(input("Enter an integer from 1 to 9: "))
        count1 = 0
        while count1 != 2:
            count1 +=1
            if guess<n:
                 print("Guess is low")
                 guess = int(input("Enter an integer from 1 to 9: ")) 
            elif guess>n:
                 print ("Guess is high")
                 guess = int(input("Enter an integer from 1 to 9: "))    
            else:
                 print("You guessed it!")
                 print("You took", count1, 'tries')
                 break
            if count1 == 2 and guess != n: 
                print("Exceeded trial limit. The answer was", n)
                break
            elif count1==2 and guess==n:
                print ("you guessed it!")
                print ("you took", count1 + 1, 'tries')
                       
      


    elif option == 2:
     k = random.randint(55,66)
     print('Calculate sum of 5 integers starting from', k)
     answer = int(input('Ans: '))
     som = 0
     for i in range(0,5):
        som += k
        k += 1
     if answer != som:
         print ('Incorrect')
     else:
         print('Correct')
       
          

       

    elif option != 1 and option != 2:
     print("Oops", option, "doesn't exist :(")



   
  



    
    
    
 





 
