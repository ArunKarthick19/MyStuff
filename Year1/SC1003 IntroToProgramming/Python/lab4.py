import re
import random
print ("Choose on of the follwoing:")
print ("    1.Register")
print ("    2.Login")
print ("    3.Play game as guest")


Udict = {'Roy': 'Clown1234',
         'Jack': 'ASDF1234',
         }

def Register():
    
        NewUser = str(input("Type your username: "))
        while NewUser in Udict:
            print('Username has been taken')
            NewUser = str(input("Input username: "))
        NewPassword=str(input('Input password: '))
        pwd = False
        while pwd != True:
            if (len(NewPassword)<9):
                print("Password too short")
                NewPassword=str(input("Input password again:"))
            elif not re.search("[1-9]",NewPassword):
                print("Password has no numbers")
                NewPassword=str(input("Input password again:"))
            elif not re.search("[a-z]", NewPassword):
                print("Password doesnt have lowercase letter")
                NewPassword=str(input("Input password again:"))
            elif not re.search("[A-Z]", NewPassword):
                print("Password doesnt have uppcase letter")
                NewPassword=str(input("Input password again:"))
            else:
                print("Valid password. User registered")

                Udict[NewUser] = NewPassword
                print(Udict)
                break
        x = int(input("Press 2 to Login: "))
        if x ==2:
            Login()
        
def Login():
        print ('login')
        Loginusername = str(input("Type your username: "))
        while Loginusername not in Udict:
            print ('Doesnt exist')
            Retry = int(input("Press 1 to try again or press 2 to register: "))
            if Retry == 1:
                Loginusername = str(input("Type your username again: "))
            if Retry ==2:
                Register()
            else:
                print("Option doesn't exist")       
        LoginPassword=str(input('Input password: '))
        while LoginPassword != Udict[Loginusername]:
            print ('wrong password')
            LoginPassword=str(input('Input password again: '))
        else:
            print('Welcome')
            
        x = int(input("Press 3 to playgame: "))
        if x ==3:
            Gamemenu()
        
def Gamemenu():
        print ("What game you want to play: ")
        print ('    1.Guessing game: ')
        print ("    2.Sum game")
        def GameOption(y):
            if y == 1:
                n = random.randint(1,9)
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
                
            elif y == 2:
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
            

            elif y !=1 or y!= 3:
                print("Option doesn't exist")
                WholeFlow(3)
                                
        y = int(input("Choose 1 or 2: "))
        GameOption(y)

def main(x):
    if x ==1:
        Register()
    if x == 2:
        Login()
    if x ==3:
        Gamemenu()

x = int(input("Choose 1 or 2 or 3: "))
main(x)      
    
    
 
