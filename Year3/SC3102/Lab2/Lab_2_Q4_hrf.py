import numpy as np
import matplotlib.pyplot as plt

times = np.arange(0, 40, 0.1)
n_time_points = len(times)

def hrf(t):
    "A hemodynamic response function"
    return t ** 8.6 * np.exp(-t / 0.547)

hrf_times = np.arange(0, 20, 0.1)
hrf_signal = hrf(hrf_times)

plt.figure()
plt.plot(hrf_times, hrf_signal)
plt.xlabel('time (seconds)')
plt.ylabel('BOLD signal')
plt.title('Estimated BOLD signal for event at time 0')

neural_signal = np.zeros(n_time_points)
i_time_4 = int(4 / 0.1)
i_time_10 = int(10 / 0.1)
i_time_20 = int(20 / 0.1)

neural_signal[i_time_4] = 2  # An impulse with amplitude 2
neural_signal[i_time_10] = 1  # An impulse with amplitude 1
neural_signal[i_time_20] = 3 # An impulse with amplitude 3


plt.figure()
plt.plot(times, neural_signal)
plt.xlabel('time (seconds)')
plt.ylabel('neural signal')
plt.ylim(0, 3.2)
plt.title('Neural model for three impulses')

n_hrf_points = len(hrf_signal)
bold_signal = np.zeros(n_time_points)
bold_signal[i_time_4:i_time_4 + n_hrf_points] = hrf_signal * 2
bold_signal[i_time_10:i_time_10 + n_hrf_points] += hrf_signal * 1
bold_signal[i_time_20:i_time_20 + n_hrf_points] += hrf_signal * 3

plt.figure()
plt.plot(times, bold_signal)
plt.xlabel('time (seconds)')
plt.ylabel('bold signal')
plt.title('Output BOLD signal for three impulses')
plt.show()

# The Convolution algo implemented manually is the same as np.convolve, which confirms that our algorithm is correct.
# the output of the linear time invariant system (the BOLD signal) can be computed by convolving the input neural signal with the system's impulse response function  
