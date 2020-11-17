syms x;
f(x)=input('Fonksiyon: ');             %x^3 - 4*x^2 - 4*x + 15
t(x)=diff(f);

x1=input('Baslangic x degeri:');
eps=input('Epsilon degeri:');

x2=x1-f(x1)/t(x1);                                  
fark=abs(x2-x1);

fprintf('\nx1:\t\t\t\tx2\t\t\t\tx2-x1:\n');
fprintf('%f\t\t%f\t\t%f\n', x1, x2, x2-x1);

while fark>eps
    x1=x2;
    x2=x1-f(x1)/t(x1);
    fark=abs(x2-x1);  
    fprintf('%f\t\t%f\t\t%f\n', x1, x2, x2-x1);
end
fprintf('\nYaklasik kok: %f', x2);