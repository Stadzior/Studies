function [optimalPath] =  SalesmanProblemSolver(fieldWidth,points,color)
%funkcja znajduj¹ca najkrótsz¹ drogê dla komiwoja¿era
%Opis alogrytmu:
% 1.Wybieram najbli¿szego mo¿liwego do wyboru s¹siada je¿eli nie ma 
% ¿adnego to przechodzê do kroku 4.
% 
% 2.Je¿eli "zagradzam" drogê do wierzcho³ka startu lub jakiegokolwiek 
% nieodwiedzonego wierzcho³ka to porzucam wybór zaznaczam wierzcho³ek jako 
% niemo¿liwy do wybrania w obecnym kroku i przechodzê do kroku 1.
% 
% 3.Pokonujê odcinek miêdzy obecnym a wybranym wierzcho³kiem i przechodzê 
% do kroku 1.
% 
% 4.Je¿eli jestem na starcie to przechodzê do kroku 7.
% 
% 5.Je¿eli zosta³ do odwiedzenia tylko start to idê do startu i przechodzê 
% do kroku 7.
% 
% 6.Je¿eli jest odcinek, o który mo¿na siê cofn¹æ to zaznaczam obecny 
% wierzcho³ek jako niemo¿liwy do wybrania w obecnym kroku i cofam ostatni 
% ruch, przechodzê do kroku 1.
% 
% 7.Koñczê dzia³anie.

amountOfPoints = size(points,1);
optimalPath = zeros(1,amountOfPoints+1);
startPoint = points(findVertexById(points,1),:);
unvisitedVertices = points;
unvisitedVertices(findVertexById(unvisitedVertices,startPoint(1)),:) = [];
availableVertices = unvisitedVertices;
currentVertex = startPoint;
i=1;
overallDistance = 0;
optimalPath(i) = startPoint(1);
while i<amountOfPoints+1;
    
    bestNeighbour = findNearestNonCrossingNeighbour(fieldWidth,startPoint,currentVertex,availableVertices);
    if (bestNeighbour==-1)
        if(currentVertex(1)==startPoint(1))
            disp('jestem na starcie - wychodze');
            %Jesteœ na starcie zakoñcz
            break;
        elseif(size(unvisitedVertices,1)==0)
            disp('idê na start - wychodze');
            %Idz na start i zakoñcz
            x1= [currentVertex(2) startPoint(2)];
            y1= [currentVertex(3) startPoint(3)];
            line(x1,y1,'Color',color);
            currentVertex = startPoint;
            optimalPath(i+1) = currentVertex(1);
            break;
        else
            %Wycofywanie kroku
            disp('wycofuje krok');
            revertedVertex = points(findVertexById(points,optimalPath(i)),:);
            unvisitedVertices = [unvisitedVertices;revertedVertex];
            optimalPath(i) = 0;
            i=i-1;
            lastCorrectVertex = findVertexById(points,optimalPath(i));
            currentVertex = points(lastCorrectVertex,:);
        end;
    else
        %Przejœcie do kolejnego wierzcho³ka
        i=i+1;
        oldVertex = currentVertex;
        currentVertex = unvisitedVertices(findVertexById(unvisitedVertices,bestNeighbour),:);
        unvisitedVertices(findVertexById(unvisitedVertices,bestNeighbour),:)=[];
        availableVertices = unvisitedVertices;
        optimalPath(i) = currentVertex(1);
        disp([num2str(oldVertex(1)), ' -> ', num2str(currentVertex(1))]);
        overallDistance=overallDistance+sqrt(power(abs(oldVertex(2)-currentVertex(2)),2)+power(abs(oldVertex(3)-currentVertex(3)),2));
        x1  = [oldVertex(2) currentVertex(2)];
        y1  = [oldVertex(3) currentVertex(3)];
        line(x1,y1,'Color',color);
    end;

end;
disp(optimalPath);
disp(overallDistance);
return
end