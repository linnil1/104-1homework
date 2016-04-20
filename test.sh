
for i in */*.cpp 
do
	sed --in-place '/PROGRAMMER/d' $i
done
