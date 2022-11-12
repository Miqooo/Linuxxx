mkdir rau
cd rau
mkdir rau_0 rau_1
cd rau_1
touch simple
ls && cd ../rau_0
mv ../rau_1/simple simple
cd ../../ && rm -r rau