CXXFLAGS=`pkg-config --cflags opencv`
#LDFLAGS=-g -L/usr/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videostab -lopencv_esm_panorama -lopencv_facedetect -lopencv_imuvstab -lopencv_tegra -lopencv_vstab -L/usr/local/cuda/lib -lcufft -lnpps -lnppi -lnppc -lcudart -lrt -lpthread -lm -ldl
LDFLAGS=`pkg-config --libs opencv`

main: main.cpp
	$(CXX) $< $(CXXFLAGS) $(LDFLAGS) -o $@

clean:
	rm -rf main *.o
