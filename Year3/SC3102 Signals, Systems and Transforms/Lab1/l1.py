import numpy as np
import matplotlib.pyplot as plt
from scipy import signal
from scipy import io # submodule to load the signal we want

##############################################################################################################

#1 this is the code for plotting various continuous-time signals

##############################################################################################################
#Continuous-like time axis
x = np.linspace(-12.5, 12.5, 101)
f = 0.1

#---- Signals ----
y1  = np.sin(2 * np.pi * f * x)              # Sine
y2  = np.cos(2 * np.pi * f * x)              # Cosine

y3  = np.zeros_like(x)                        # Unit impulse (approx)
mid = len(x) // 2
y3[mid] = 1

y4  = np.where(x >= 0, 1, 0)                  # Unit step
y5  = np.where((x > -3) & (x < 3), 1, 0)      # Square pulse
y6  = signal.sawtooth(2 * np.pi * f * x, 0.5) # Triangular
y7  = np.exp(0.2 * x)                         # Exponential
y8  = signal.sawtooth(2 * np.pi * f * x)      # Sawtooth
y9  = np.sign(x)                              # Signum
y10 = np.sinc(x)                              # Sinc (np.sinc = sin(pi x)/(pi x))

signals = [
    ("Sine Wave", y1),
    ("Cosine Wave", y2),
    ("Unit Impulse (approx)", y3),
    ("Unit Step", y4),
    ("Square Wave (pulse)", y5),
    ("Triangular Wave", y6),
    ("Exponential Wave", y7),
    ("Sawtooth Wave", y8),
    ("Signum Function", y9),
    ("Sinc Wave", y10),
]

# ---- Plot (5 rows x 2 cols) ----
fig, axes = plt.subplots(5, 2, figsize=(12, 14))
axes = axes.ravel()

for i, (title, y) in enumerate(signals):
    ax = axes[i]

    # Make impulse look like an impulse
    if title.startswith("Unit Impulse"):
        ax.plot(x, y, marker='o', linestyle='None')  # just points
        ax.vlines(x[mid], 0, 1, linewidth=2)         # vertical spike at 0
        ax.set_ylim(-0.1, 1.1)
    else:
        ax.plot(x, y)

    ax.set_title(title)
    ax.set_xlabel("x")
    ax.set_ylabel("Amplitude")
    ax.grid(True)

plt.tight_layout()
plt.show()


##############################################################################################################

#2.1 this is the code for sampling a sine wave at different sampling frequencies
#Sampling below the Nyquist rate causes aliasing and loss of information. Sampling at or above the Nyquist rate allows accurate reconstruction of the original signal.
#sampling freq must be equal to or greater than twice the highest frequency present in the signal

##############################################################################################################


Fm = 100 #Frequency of sine wave

t1 = np.linspace (0,0.1,200)

yl = np.sin(2 * np.pi * Fm * t1 + np.pi/6) #Sine wave

fig, axs =  plt.subplots (1, 2, figsize=(10, 4), constrained_layout=True)
axs[0].plot(t1, yl, label='continuous')
axs[0].set_title("Sine wave")
axs[0].set_xlabel('time in sec')
axs[0].set_ylabel('y(t)')
 

#fs1=int(input("Enter the sampling frequency : ")) #sampling rate
#sampling rate
#400Hz is above
#200Hz is at
#Anything below 200Hz is below the Nyquist rate for a 100Hz signal
fs1 = 200 
n1 = np.arange(0,0.1*fs1)/fs1
x1=np.sin(2 * np.pi * Fm * n1 + np.pi/6); 
axs[1].plot(n1,x1,'b')
axs[1].set_title("discrete time signal x(n) with fs = " + str(fs1))
axs[1].set_xlabel('time in sec')
axs[1].set_ylabel('y(t)')

plt.show()


##############################################################################################################

#2.2 this is the code for adding two cosine waves of different frequencies and plotting the result

##############################################################################################################
#define gcd function
def gcd(x, y):
   """This function implements the Euclidian algorithm
   to find G.C.D. of two numbers"""

   while(y):
       x, y = y, x % y

   return x

# define lcm function
def lcm(x, y):
   """This function takes two
   integers and returns the L.C.M."""
   lcm = (x*y)//gcd(x,y)
   return lcm

# define the main function 
def main():
   A=0.5; F1=10; Phi = 0; Fs=60; sTime=0; eTime = 1;
   #2*pi*10/60 => w1= pi/3 => N =6
   t1 = np.arange(sTime,eTime,1.0/Fs)
   y1 = A*np.cos(2 * np.pi * F1 * t1 + Phi)
   B=0.3; F2=15;
   #2*pi*15/60 => w2=pi/2 => N = 4
   t2 = np.arange(sTime,eTime,1.0/Fs)
   y2 = B*np.cos(2 * np.pi * F2 * t2 + Phi)
   
   y3 = y1+y2

   #how many samples to store J cycles of y
   nSamplesPeriod1 = int(Fs/F1)
   nSamplesPeriod2 = int(Fs/F2)
   nSamplesPeriod_LCM = lcm( int(nSamplesPeriod1),int(nSamplesPeriod2))
   # When we have two signals, the Least common mutiplier is the period of the added waveform!
    #what this is doing is finding the LCM of the two periods to determine the period of the combined signal y3

   s = 'Number of samples per cycle N1='+ repr(nSamplesPeriod1)+'  N2='+ repr(nSamplesPeriod2) + '  LCM = '+ repr(nSamplesPeriod_LCM)
   print(s)
   nSamplesPeriod_int = int(nSamplesPeriod_LCM)

   J = 3   # lets plot J cycles
   plt.figure(1)
   #plt.plot(t1[0:nSamplesPeriod_int*J], y1[0:nSamplesPeriod_int*J],'r--o')
   #plt.plot(t1[0:nSamplesPeriod_int*J], y2[0:nSamplesPeriod_int*J],'g--o')
   plt.plot( y1[0:nSamplesPeriod_int*J],'r--o',label='y1')
   plt.plot( y2[0:nSamplesPeriod_int*J],'g--o',label='y2')
   plt.xlabel('sample n'); plt.ylabel('y[n]')
   plt.legend()
   plt.grid()

   plt.figure(2)
   #plt.plot(t1[0:nSamplesPeriod_int*J], y3[0:nSamplesPeriod_int*J],'b--o')
   plt.plot( y3[0:nSamplesPeriod_int*J],'b--o',label='y3')
   plt.xlabel('sample n'); plt.ylabel('y[n]')
   plt.grid()
   plt.legend()
   plt.show()
  

if __name__ == '__main__':
    main()


##############################################################################################################

#3.1 this loads the data from the .mat file into a Python dictionary

##############################################################################################################
#.mat file shld be in the same folder as this script for this to work
EEG_data = io.loadmat('EEG_exp.mat', squeeze_me = True)

# print all the variables that exist in the dictionary
print(EEG_data.keys())

# this contains the EEG data
EEG = EEG_data['EEG']
# this contains the sampling rate, in Hz (or samples/second)
fs = EEG_data['fs']

# let's plot the signal
plt.figure(figsize=(15,3))
plt.plot(EEG)
# ALWAYS label your plot axes in this course (and ever)
plt.xlabel('Sample Number')
plt.ylabel('Voltage (uV)')

#Zoomed in version
# now let's zoom in to see more detail
plt.figure(figsize=(15,3))
plt.plot(EEG) # '.' means plot the data points as individual dots without linking them
plt.xlim([0,1000]) # this limits the x-axis shown
plt.ylim([-15, 15]); # this limits the y-axis shown
plt.xlabel('Sample Number')
plt.ylabel('Voltage (uV)')
plt.show()



##############################################################################################################

#3.2 this loads the data from the .mat file into a Python dictionary and digitizes it using an ADC(analog digital conversion) model


'''
What does a 4-bit ADC mean?
Number of bits = 4
Voltage levels = 2^number of bits = 2^4 = 16 levels 
So the signal can only take 16 discrete amplitude values.
Why 4 bits? it's just an example, in real life ADCs can have 8, 10, 12, 16, 24 bits or more
What are the voltage levels? it depends on the voltage range of the signal being digitized
Here we assume the voltage range is -32uV to +32uV
'''

##############################################################################################################
EEG_data = io.loadmat('EEG_exp.mat', squeeze_me = True)

# print all the variables that exist in the dictionary
print(EEG_data.keys())

# this contains the EEG data
EEG = EEG_data['EEG']
# this contains the sampling rate, in Hz (or samples/second)
fs = EEG_data['fs']


num_bits = 4
min_v, max_v = -32,32

num_levels = 16 
delta_v = 4 #step size

# create the digitization vector, these are the new possible values that your signal can take
ADC_levels = np.arange(min_v,max_v,delta_v)+delta_v/2

# digitize the EEG signal with our ADC with the function np.digitize
# note that we have to scale the redigitized signal to its original units
EEG_quant = np.digitize(EEG,bins=ADC_levels)*delta_v+min_v

plt.figure(figsize=(15,4))
plt.plot(EEG, label='Original EEG')
plt.plot(EEG_quant, label='Digitized EEG', alpha=0.8)
plt.xlim([0,1000]); plt.ylim([-15, 15]);
plt.legend()
plt.xlabel('Sample Number')
plt.ylabel('Voltage (uV)')
plt.show()

##############################################################################################################

#3.3 #this loads the data from the .mat file into a Python dictionary and downsamples it
#downsampling means reducing the sampling rate of a signal by keeping only every Nth sample and discarding the rest

##############################################################################################################

EEG_data = io.loadmat('EEG_exp.mat', squeeze_me = True)

# print all the variables that exist in the dictionary
print(EEG_data.keys())

# this contains the EEG data
EEG = EEG_data['EEG']
# this contains the sampling rate, in Hz (or samples/second)
fs = EEG_data['fs']

dt = 0.001  
T_exp = 720  
t_EEG = np.arange(0,720,0.001)  
d_rate = 10 #Downsampling rate

# Plotting the signal and its downsampled version
plt.figure(figsize=(15,3))

plt.plot(t_EEG, EEG, label='EEG')
plt.plot(t_EEG[1:1000:d_rate], EEG[1:1000:d_rate], '.-', label='Downsampled', alpha=0.8)
plt.xlim([0,1]); plt.ylim([-15, 15]);
plt.legend()
plt.xlabel("Time")
plt.ylabel("Voltage")
plt.show()
