%mapping through ultrasonic sensor pan tilt mechanism
%program 1
%Arduino to matlab code
arduino=serial('COM4','BaudRate',9600); 
fopen(arduino); 
j=1; 
for i=1:10000 
a(i)=fscanf(arduino,"%f"); 
n(i)=j; 
j=j+1; 
end 
disp(a); 
fclose(arduino); 
delete(instrfind({'Port'},{'COM4'})); 