import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

impulseH1 =  [0.06523, 0.14936,0.21529,0.2402,0.21529,0.14936,0.06523]
impulseH2 =  [-0.06523, -0.14936,-0.21529,0.7598,-0.21529,-0.14936,-0.06523]
impulseH3 = np.convolve(impulseH1,impulseH2)

x1 = np.zeros(30)
x1[0]  = 1

plt.figure()
y_float1  = np.convolve(x1,impulseH1)
y_float2  = signal.lfilter(impulseH1,[1], x1)
# showing that convolution can be realised by np.convolve and scipy.signal.lfilter(BCooeff,[1],impulseX)
plt.stem(y_float1, linefmt='r--')
plt.plot(y_float2, 'g-+')
plt.title('impulse response of H1')
plt.xlabel('sample n'); plt.ylabel('H1[n]')

plt.figure()
y_float1  = np.convolve(x1,impulseH2)
y_float2  = signal.lfilter(impulseH2,[1], x1)
# showing that convolution can be realised by np.convolve and scipy.signal.lfilter(BCooeff,[1],impulseX)
plt.stem(y_float1, linefmt='r--')
plt.plot(y_float2, 'g-+')
plt.title('impulse response of H2')
plt.xlabel('sample n'); plt.ylabel('H2[n]')

plt.figure()
y_float1  = np.convolve(x1,impulseH3)
y_float2  = signal.lfilter(impulseH3,[1], x1)
# showing that convolution can be realised by np.convolve and scipy.signal.lfilter(BCooeff,[1],impulseX)
plt.stem(y_float1, linefmt='r--')
plt.plot(y_float2, 'g-+')
plt.title('impulse response of H3')
plt.xlabel('sample n'); plt.ylabel('H3[n]')
plt.show()

# the impulse response of H3 is the convolution of the impulse responses of H1 and H2,
#  which confirms that the convolution operation is associative. meaning impulse response of the cascaded system 
# is the convolution of the impulse responses of the individual systems.