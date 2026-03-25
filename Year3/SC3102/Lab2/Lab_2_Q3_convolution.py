import numpy as np
import matplotlib.pyplot as plt

n_samples = 100 # number of samples in the signal

signal = np.zeros(n_samples)
signal[np.random.randint(0 ,n_samples, 5)] = 1  # set 5 random samples to 1, the rest are 0


plt.figure()
plt.plot(signal, linewidth=2)
plt.xlabel('Time')
plt.ylabel('Signal Intensity')
plt.title('Signal ')

kernel = np.zeros(10)
kernel[2:8] = 1 # create a boxcar kernel of width 6 (from index 2 to 7)

plt.figure()
plt.plot(kernel, linewidth=2, color='red')
plt.xlabel('Time')
plt.ylabel('Intensity')
plt.title('Kernel ')

shifted_kernel = np.zeros((n_samples, n_samples+len(kernel) - 1))#shift kernel to create a convolution matrix
rev_kernel = kernel[::-1] # reverse the kernel for convolution, since convolution is equivalent to correlation with a flipped kernel
for i in range(n_samples):
    shifted_kernel[i, i:i+len(kernel)] = rev_kernel

convolved_signal = np.dot(signal, shifted_kernel) # convolve the signal with the kernel using matrix multiplication

plt.figure()
plt.plot(convolved_signal, linewidth=2)
plt.ylabel('Intensity')
plt.xlabel('Time')
plt.title('Signal convolved with boxcar kernel')
plt.show()
