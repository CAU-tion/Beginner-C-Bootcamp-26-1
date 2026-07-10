challenge1  
![ch1](./w2ch1c.png)  
![ch1r](./w2ch1r.png)  
각각의 바이트 크기를 나타내고 8비트가 1바이트이므로 int의 경우 32바이트를 할당한다고 볼 수 있다.

challenge2  
![ch2](./w2ch2c.png)  
![ch2r](./w2ch2c.png)  
a:2(10) -> 10(2)
b:3(10) -> 11(2)

AND:10  
OR:11  
XOR:01  
NOT:01(-부호)  
<<:100  
">>":1  

challenge3  
![ch3](./w2ch3c.png)  
![ch3r](./w2ch3c.png)  
char:[-128,127]
unsigned char:[0,255]
오버플로우 시 부호를 결정하는 메모리 변화 -> 부호 변화 + 최소값
unsigned의 경우 변화해도 0
