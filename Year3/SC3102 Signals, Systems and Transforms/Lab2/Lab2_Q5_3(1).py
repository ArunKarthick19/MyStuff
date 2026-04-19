import numpy as np
import matplotlib.pyplot as plt

impulseH1 =  [0.06523, 0.14936,0.21529,0.2402,0.21529,0.14936,0.06523]
impulseH2 =  [-0.06523, -0.14936,-0.21529,0.7598,-0.21529,-0.14936,-0.06523]
impulseH3 = np.convolve(impulseH1,impulseH2)

x1 = np.zeros(30)
x1[0]  = 1

x2 = np.zeros(30)
x2[15] = -2

plt.figure()
y_float1  = np.convolve(x1,impulseH3)
y_float2  = np.convolve(x2,impulseH3)
y_new1 = y_float1+y_float2
plt.stem(y_new1,linefmt='r--')
plt.plot(y_new1,'g-+')
plt.title('y1[n]+y2[n]')
plt.xlabel('sample n'); plt.ylabel('y[n]')

# plotting y due to h2 and x1
plt.figure()
y_new2  = np.convolve(x1+x2,impulseH3)
plt.stem(y_new2,linefmt='r--')
plt.plot(y_new2,'g-+')
plt.title('h3[n]*(x1[n]+x2[n])')
plt.xlabel('sample n'); plt.ylabel('y[n]')
plt.show()


#both the graphs are the same, which confirms that the convolution operation is linear.
#confirms superposition property