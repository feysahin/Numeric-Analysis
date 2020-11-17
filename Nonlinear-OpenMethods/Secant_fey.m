syms x;
f(x)=input('Fonksiyon: ');                %x^3-20*x+16
eps=input('Epsilon degeri:');
x1=input('Ilk x degeri:');
x2=input('Son x degeri:');         

fprintf('\nx1:\t\t\tf(x1):\t\t\t x2:\t\t f(x2):\t\t\t x3:\t\t f(x3):\n');

if f(x1)*f(x2)<0
    x3=x2-((x2-x1)*f(x2))/(f(x2)-f(x1));
    fprintf('%f\t%f\t\t %f\t %f\t\t %f\t %f\n', x1, f(x1), x2, f(x2), x3, f(x3));
    fark=abs(x2-x1);
    x3_degeri=abs(f(x3));
    while fark>eps && x3_degeri>eps            
        if f(x1)*f(x3)<0
            x2=x3;
        else
            x1=x3;
        end
        x3=x2-((x2-x1)*f(x2))/(f(x2)-f(x1));   
        fark=abs(x2-x1);
        x3_degeri=abs(f(x3));
        fprintf('%f\t%f\t\t %f\t %f\t\t %f\t %f\n', x1, f(x1), x2, f(x2), x3, f(x3));
    end   
else
    fprintf('Arada kok olmayabilir.');
end
fprintf('\nYaklasik kok: %f', x3);