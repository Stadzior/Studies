function [crossCanOccur] = crossCanOccur(fieldWidth,pointFrom,pointTo,startPoint,availableVertices)
%Funkcja sprawdzaj�ca czy dany odcinek mo�e powodowa� przecinanie si�
%trasy komiwoja�era.
crossCanOccur = false;

%Wyznaczanie r�wnania nowego odcinka
% aNewPath = (pointTo(3)-pointFrom(3))/(pointTo(2)/pointFrom(2));
% bNewPath = pointFrom(3)-aNewPath*pointFrom(2);

%Dodanie do badanych wierzcho�k�w wierzcho�ka startu oraz usuni�cie
%wierzcho�k�w sk�adaj�cych si� na nowy odcinek
testingPoints = [availableVertices;startPoint];

pointFromPosition = findVertexById(testingPoints,pointFrom(1));
if (pointFromPosition>0)
    testingPoints(pointFromPosition,:) = [];
end;

pointToPosition = findVertexById(testingPoints,pointTo(1));
if (pointToPosition>0)
    testingPoints(pointToPosition,:) = [];
end;

for i=1:size(testingPoints,1);    
    %Wyznaczanie r�wnania kolejnych �cie�ek mi�dzy nie odwiedzonymi
    %wierzcho�kami
    for j=i+1:size(testingPoints,1);
        testingPointFrom = testingPoints(i,:);
        testingPointTo = testingPoints(j,:);
%         aTestPath = (testingPointTo(3)-testingPointFrom(3))/(testingPointTo(2)/testingPointFrom(2));
%         bTestPath = testingPointFrom(3)-aTestPath*testingPointFrom(2);
%         
%         crossCanOccur = isCrossing(fieldWidth,aNewPath,bNewPath,aTestPath,bTestPath);
          crossCanOccur = isCrossing(pointFrom(2),pointFrom(3),pointTo(2),pointTo(3),testingPointFrom(2),testingPointFrom(3),testingPointTo(2),testingPointTo(3));
          if (crossCanOccur == true)
            break;
          end;
    end;
    if (crossCanOccur == true)
        break;
    end;
end;
return
end

