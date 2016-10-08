clear
clc

crossingProb = 0.90;
mutationProb = 0.10;
SectionMAX = 127;
N=input('Podaj liczbê chromosomów\n');
countOfIterations=input('Podaj liczbê iteracji\n');
PopulationDec = ceil(rand(1,N)*SectionMAX)';
PopulationBin=dec2bin(PopulationDec);

for mainIterator = 1:countOfIterations
    %Selekcja
    disp('###################### Selekcja... #############################');
    populationDec = PerformSelection(PopulationDec);
    populationBin = dec2bin(PopulationDec);    
    populationCount = size(PopulationBin,1); %Przeliczenie licznoœci populacji po selekcji na zaœ
    
    %Losowanie lokusa od 1 do (liczba bitów - 1)
    locus = ceil(rand(1)*size(PopulationBin,2)-1); 
    disp(['Wylosowano lokus: ',num2str(locus)]);
    
    %Krzy¿owanie
    disp('###################### Krzy¿owanie... ##########################');
    pairs = randperm(populationCount);
    for i = 1:floor(populationCount/2)
        willItCross = rand(1)<crossingProb;
        if(willItCross)
         disp('_______________________________');
         disp([num2str(PopulationDec(pairs(i))),' <---> ',num2str(PopulationDec(pairs(i+floor(populationCount/2)))),' powsta³o']);
         
         firstChild = PerformCrossing(PopulationBin(pairs(i),:),PopulationBin(pairs(i+floor(populationCount/2)),:),locus);
         secondChild = PerformCrossing(PopulationBin(pairs(i+floor(populationCount/2)),:),PopulationBin(pairs(i),:),locus);
         PopulationBin(pairs(i),:) = firstChild;
         PopulationBin(pairs(i+floor(populationCount/2)),:) = secondChild;
         
         PopulationDec = bin2dec(PopulationBin);
         
         disp([num2str(bin2dec(firstChild)),', ',num2str(bin2dec(secondChild))]);
        end;
    end;

    %Mutacja
    disp('###################### Mutacje... ########################');
    for i = 1:populationCount
        willItMutate = rand(1)<mutationProb;
        if(willItMutate)
            disp('________________');
            disp([num2str(PopulationDec(i)),' zmutowa³ do ']);
            
            PopulationBin(i,:) = PerformMutation(PopulationBin(i,:),locus);
            PopulationDec = bin2dec(PopulationBin);
            
            disp(num2str(PopulationDec(i)));
        end;
    end; 
    
    disp('###################### Wynik... ########################');
    result = PopulationDec(AdaptationFunction(PopulationDec) == max(AdaptationFunction(PopulationDec)));
    disp(['Wynik po ',num2str(mainIterator),' iteracji wynosi: ',num2str(result(1))]); 
end;
%Losowanie ruletki vector