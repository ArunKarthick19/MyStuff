import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

impulseH1 =  [0.06523, 0.14936,0.21529,0.2402,0.21529,0.14936,0.06523]
impulseH2 =  [-0.06523, -0.14936,-0.21529,0.7598,-0.21529,-0.14936,-0.06523]
impulseH3 = np.convolve(impulseH1,impulseH2)

x1 = np.zeros(30)
x1[0]  = 1
x1[15] = -2

# plotting y due to h1 and x1
plt.figure()
y_float1  = np.convolve(x1,impulseH1)
y_float2  = signal.lfilter(impulseH1,[1], x1)
# Lets save the file, fname, sequence, and samplingrate needed
plt.stem(y_float1,linefmt='r--')
plt.plot(y_float2,'g-+')
plt.title('x convolve with H1')
plt.xlabel('sample n'); plt.ylabel('y[n]')

# plotting y due to h2 and x1
plt.figure()
y_float1  = np.convolve(x1,impulseH2)
y_float2  = signal.lfilter(impulseH2,[1], x1)
# Lets save the file, fname, sequence, and samplingrate needed
plt.stem(y_float1,linefmt='r--')
plt.plot(y_float2,'g-+')
plt.title('x convolve with H2')
plt.xlabel('sample n'); plt.ylabel('y[n]')

# plotting y due to h3 and x1
plt.figure()
y_float1  = np.convolve(x1,impulseH3)
y_float2  = signal.lfilter(impulseH3,[1], x1)
# Lets save the file, fname, sequence, and samplingrate needed
plt.stem(y_float1,linefmt='r--')
plt.plot(y_float2,'g-+')
plt.title('x convolve with H3')
plt.xlabel('sample n'); plt.ylabel('y[n]')
plt.show()


