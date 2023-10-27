class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // Classifique o vetor de satisfação em ordem crescente
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();  
        int counter = 1;
        vector<int> timeIncrement;  // Vetor para armazenar o incremento de tempo

        // Crie um vetor de incremento de tempo de 1 a n
        for(int i = 0; i < n; i++) {
            timeIncrement.push_back(counter);
            counter++;
        }

        int maximumSatisfaction = 0;  

        // Loop através de cada elemento do vetor de satisfação
        for(int i = 0; i < n; i++) {
            int currentSum = 0;  // Variável para rastrear a soma atual

            // Calcule a soma atual considerando o incremento de tempo
            for(int j = i; j < n; j++) {
                if (timeIncrement[j] < 0) return maximumSatisfaction;
                currentSum += timeIncrement[j] * satisfaction[j];
            }

            maximumSatisfaction = max(maximumSatisfaction, currentSum);

            // Reduza o incremento de tempo para o próximo elemento
            for(int k = i; k < n; k++) {
                timeIncrement[k] -= 1;
            }
        }

        return maximumSatisfaction;  
    }
};
