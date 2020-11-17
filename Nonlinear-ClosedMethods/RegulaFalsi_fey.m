syms x;
f(x)=input('Fonksiyon: ');                   %x^3-5*x-7
eps=input('Epsilon degeri:');
x1=input('Ilk x degeri:');
x2=input('Son x degeri:');

if f(x1)*f(x2)<0
  x3=((x2)*f(x1)-(x1)*f(x2))/(f(x1)-f(x2));
  fark=abs(x2-x1);
  x3_degeri=abs(f(x3));
  
  fprintf('\nx1:\t\t\t f(x1):\t\t\t x2:\t\t f(x2):\t\t\t x3:\t\t f(x3):\n');
  fprintf('%f\t%f\t\t %f\t %f\t\t %f\t %f\n', x1, f(x1), x2, f(x2), x3, f(x3));
      
  while fark>eps && x3_degeri>eps        
      if f(x3)*f(x1)<0
          x2=x3;
      else 
          x1=x3;
      end
      x3=((x2)*f(x1)-(x1)*f(x2))/(f(x1)-f(x2));
      fark=abs(x2-x1);
      x3_degeri=abs(f(x3));
      fprintf('%f\t%f\t\t %f\t %f\t\t %f\t %f\n', x1, f(x1), x2, f(x2), x3, f(x3));
  end
else
    fprintf('Arada kok olmayabilir.');
end 
fprintf('\nYaklasik kok: %f', x3);