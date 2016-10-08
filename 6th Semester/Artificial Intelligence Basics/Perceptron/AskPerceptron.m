function [t] = AskPerceptron(x,y)

[w,b] = LearnPerceptron;

if (y>(w*x)+b)
    t=1;
else
    t=0;
end;
return
end

