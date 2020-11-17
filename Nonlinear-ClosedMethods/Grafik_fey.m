syms x;
f(x)=input('Fonksiyon: ');                  %x^2-6*x+5
eps=input('Epsilon degeri:');
x1=input('Ilk x degeri:');
delta_x=input('Delta x degeri:');     

fprintf('\nx1:\t\t\t\tf(x1):\n');

while delta_x>eps
    while f(x1)*f(x1+delta_x)>0
        fprintf('%f\t\t%f\n', x1, f(x1));
        x1=x1+delta_x;
    end
    fprintf('%f\t\t%f\n', x1, f(x1));
    fprintf('%f\t\t%f\n', x1+delta_x, f(x1+delta_x));
    
    delta_x=delta_x/2;
    fprintf('\n');
end
while f(x1)*f(x1+delta_x)>0
    fprintf('%f\t\t%f\n', x1, f(x1));
    x1=x1+delta_x;
    fprintf('%f\t\t%f\n', x1, f(x1));
end
fprintf('%f\t\t%f\n', x1, f(x1));
fprintf('\nYaklasik kok: %f', x1);