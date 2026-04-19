import numpy as np
import matplotlib.pyplot as plt

times = np.arange(0, 40, 0.1)
n_time_points = len(times)
neural_signal = np.zeros(n_time_points)
neural_signal[(times >= 4) & (times < 9)] = 1

def hrf(t):
    "A hemodynamic response function"
    return t ** 8.6 * np.exp(-t / 0.547)

hrf_times = np.arange(0, 20, 0.1)
hrf_signal = hrf(hrf_times)

neural_signal = np.zeros(n_time_points)

i_time_4 = int(4 / 0.1)
i_time_10 = int(10 / 0.1)
i_time_20 = int(20 / 0.1)

neural_signal[i_time_4] = 2  # An impulse with amplitude 2
neural_signal[i_time_10] = 1  # An impulse with amplitude 1
neural_signal[i_time_20] = 3 # An impulse with amplitude 3


n_hrf_points = len(hrf_signal)


N = n_time_points
M = n_hrf_points
bold_signal = np.zeros(N + M - 1)  # adding the tail
for i in range(N):
    input_value = neural_signal[i]
    # Adding the shifted, scaled HRF
    bold_signal[i : i + n_hrf_points] += hrf_signal * input_value
# We have to extend 'times' to deal with more points in 'bold_signal'
extra_times = np.arange(n_hrf_points - 1) * 0.1 + 40
times_and_tail = np.concatenate((times, extra_times))
plt.figure()
plt.plot(times_and_tail, bold_signal)
plt.xlabel('time (seconds)')
plt.ylabel('bold signal')
plt.title('Output BOLD signal using our algorithm')


bold_signal = np.convolve(neural_signal, hrf_signal)
plt.figure()
plt.plot(times_and_tail, bold_signal)
plt.xlabel('time (seconds)')
plt.ylabel('bold signal')
plt.title('Our algorithm is the same as convolution')
plt.show()

'''manually convolving the neural signal with the HRF by summing the products of the neural signal and the shifted HRF at each time point, we get the same result as using np.convolve, which confirms that our algorithm is correct.   The convolution operation effectively captures the temporal dynamics of the BOLD signal in response to the neural activity, demonstrating how the HRF shapes the observed BOLD signal over time.'''