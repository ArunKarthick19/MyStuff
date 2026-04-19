#install opencv-python to import cv2
#pip3 install --upgrade opencv-python

import cv2 
import matplotlib.pyplot as plt

def simple_edge_detection(image): 
   edges_detected = cv2.Canny(image , 100, 200) 
   images = [image , edges_detected]
   location = [121, 122] 
   for loc, edge_image in zip(location, images): 
      plt.subplot(loc) 
      plt.imshow(edge_image, cmap='gray')
#    cv2.imwrite('edge_detected.png', edges_detected) 
#    plt.savefig('edge_plot.png') 
   plt.show()

img = cv2.imread('testimage.jpg', 0)
# img = cv2.imread('edgeflower.jpg', 0)
simple_edge_detection(img)