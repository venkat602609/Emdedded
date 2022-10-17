#!/usr/bin

import sys
from PIL import Image


im_in=Image.open(sys.argv[1]);
#im_out=sys.argv[2];
print("Original Size Of the Image : {im_in.size}");
resized_image=im_in.resize((16,16));
rgb_image=im_in.convert('RGB');
print("Resized image size :{resized_image.size}");
#print the 256 pixel RGB values
pixels=list(rgb_image.getdata());
#resized_image = resized_image.save(im_out);
print(pixels);
rev_ord = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15];
for_ord = [15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0];
for i in range(len(pixels)):
	if (i//16)%2!=0 :
		print("leds["+str(i)+"] = CRGB"+str(pixels[i])+";");
	else:
#		print("i Value "+str(i)+" i%16 "+str(i%16)+" revOrdValue "+str(rev_ord[i%16]));
		print("leds["+str(i+for_ord[i%16]-rev_ord[i%16])+"] = CRGB"+str(pixels[i])+";");
