#include<iostream>

void pause() {
    std::cin.ignore();
    std::cout << "Press Enter to continue ...";
    std::cin.ignore();
};

int generate(int limit) {
    int returnval = 0;
    do {
        int random = std::rand() % (limit*2 + 1);
        returnval = random - limit;
    } while (returnval == 0);
    return returnval;
};

std::string displayNum(int num) {
    if (num >= 0) {
        return " + " + std::to_string(num);
    } else {
        return " - " + std::to_string(abs(num));
    };
    return "";
};

class Factor {
    public:
        int front, back;

        Factor() {}

        void initialize(int front_limit, int back_limit) {
            front = generate(front_limit);
            back = generate(back_limit);
        }

        void display() {
            std::cout << "(" << std::to_string(front)<< "x" << displayNum(back)<< ")";
        }
};

void displayFactors(Factor factor[], int factor_count) {
    for (int i = 0; i < factor_count; ++i) {
        factor[i].display();
    }
    std::cout << "\n";
}

void generateCoefficients(Factor factor[], int factor_count, int current_number, int current_index, int order, int coefficients[]) {
    if (current_index < factor_count) {
        int front_product = current_number * factor[current_index].front;
        int back_product = current_number * factor[current_index].back;
        //std::cout<<std::to_string(current_number)<<"*"<<std::to_string(factor[current_index].front)<<"="<<std::to_string(front_product)<<"("<<std::to_string(current_index)<<","<<std::to_string(order)<<") ";
        //std::cout<<std::to_string(current_number)<<"*"<<std::to_string(factor[current_index].back)<<"="<<std::to_string(back_product)<<"("<<std::to_string(current_index)<<","<<std::to_string(order)<<")\n";
        generateCoefficients(factor, factor_count, front_product, current_index+1, order+1, coefficients);
        generateCoefficients(factor, factor_count, back_product, current_index+1, order, coefficients);
    } else {
        //std::cout << "Order "<<std::to_string(order)<<" = "<<std::to_string(current_number) << "\n";
        coefficients[order] += current_number;
    };
};

void displayProblem (Factor factor[], int factor_count) {
    // Generate a full list of all combinations, including order
    // Assign numbers to exponent based on order

    int coefficients[factor_count + 1];
    for (int i = 0; i <= factor_count; ++i) {
        coefficients[i] = 0;
    }

    generateCoefficients(factor, factor_count, 1, 0, 0, coefficients);
    /*
    for (int i : coefficients) {
        std::cout <<", "<<std::to_string(i);
    }
    std::cout<<"\n";
    */
    for (int i = factor_count; i > 0; --i) {
        std::cout << displayNum(coefficients[i]) << "x^" << std::to_string(i);
    }
    std::cout << displayNum(coefficients[0]) << "\n";
};

int main() {
    int front_limit, back_limit, factor_count, problem_count;
    std::srand(time(NULL));
    std::cout << "Enter the maximum absolute value of the coefficient of x in each factor. ";
    std::cin >> front_limit;
    std::cout << "Enter the maximum absolute value of the second term of each factor. ";
    std::cin >> back_limit;
    std::cout << "Enter the number of desired factors. ";
    std::cin >> factor_count;
    std::cout << "Number of problems. ";
    std::cin >> problem_count;
    for(int i = 0; i < problem_count; ++i) {
        Factor factor[factor_count];
        for (int i = 0; i < factor_count; ++i) {
            factor[i].initialize(front_limit, back_limit);
        }
        /*
        for (Factor i : factor) {
            i.display();
        }
        std::cout<<"\n";
        */
        displayProblem(factor, factor_count);
        pause();
        for (Factor i : factor) {
            i.display();
        }
        std::cout<<"\n";

        pause();
    }

    pause();
};