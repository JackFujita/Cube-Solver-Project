import cv2 as cv
import numpy as np


img_counter = 0  #pls explain

capture = cv.VideoCapture(0) #create a capture window (?)

while True: #loop until ESC pressed
    isTrue, frame = capture.read() #frame must be the 
    cv.rectangle(frame, (frame.shape[1]//2-100,frame.shape[0]//2-100), (frame.shape[1]//2+100, frame.shape[0]//2+100), (255,255,255), 2)
    cv.imshow('Video', frame)
    
    k = cv.waitKey(1)
    if k%256 == 27:
        # ESC pressed
        print("Escape hit, closing...")
        break
    elif k%256 == 32:
        # SPACE pressed
        img_name = "opencv_frame_{}.png".format(img_counter)
        cv.imwrite(img_name, frame)
        print("{} written!".format(img_name))
        img_counter += 1 
        img = cv.imread(img_name)

        cv.imshow("img", img)

        blank = np.zeros(img.shape[:2], dtype='uint8')
        cv.imshow('Blank', blank)

        mask = cv.rectangle(blank, (img.shape[1]//2-100,img.shape[0]//2-100), (img.shape[1]//2+100, img.shape[0]//2+100), 255, -1)
        cv.imshow("mask", mask)

        masked = cv.bitwise_and(img, img, mask=mask)
        cv.imshow("maked", masked)

        Z = masked.reshape((-1,3))
        Z = np.float32(Z)

        criteria = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_MAX_ITER, 10, 1.0)
        ret, label, center = cv.kmeans(Z, 6, None, criteria,10,cv.KMEANS_RANDOM_CENTERS)

        center = np.uint8(center)
        res = center[label.flatten()]
        res2 = res.reshape((masked.shape))

        cv.imshow('res2',res2)
        cv.waitKey(0)
        cv.destroyAllWindows()

capture.realease()
cv.destroyAllWindows()



#single

'''
multiline? maybe
'''