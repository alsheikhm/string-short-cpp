// Mohammed Al-Sheikh
// main.cpp

#include <iostream>
#include <string>
#include <stdexcept>

short ConvertToShort(const std::string& input)
{
    // Constant string error message used in throw statements
    const std::string error = "ConvertToShort: Invalid 16-bit signed integer";
    
    bool negativeFound = false;
    bool decimalFound = false;
    bool digitFound = false;

    int value = 0;
    int i = 0;
    
    // Checks if input is empty
    if(input.length() == 0)
    {
        throw std::invalid_argument(error);
    }
    
    // Checks if there is an optional leading sign
    if(input[0] == '-')
    {
        negativeFound = true;
        i = 1;
    }
    else if(input[0] == '+')
    {
        i = 1;
    }

    // Checks if input is not only the sign
    if(i == input.length())
    {
        throw std::invalid_argument(error);
    }
    
    // Checks each remaining character in the string
    for(i = i; i < input.length(); i++)
    {
        char index = input[i];
        
        // Checks if character is a digit
        if(index >= '0' && index <= '9')
        {
            digitFound = true;
            
            // Checks if decimal point has been reached, otherwise will build the value
            if(decimalFound == false)
            {
                int limit;
                int digit = index - '0';
                
                if(negativeFound == true)
                {
                    limit = 32768;
                }
                else
                {
                    limit = 32767;
                }

                if(value > (limit - digit) / 10)
                {
                    throw std::invalid_argument(error);
                }

                value = (value * 10) + digit;
            }
            else
            {
                // Checks if after the decimal point, there are only zeros
                if(index != '0')
                {
                    throw std::invalid_argument(error);
                }
            }
        }
        // Checks there is only 1 decimal point
        else if(index == '.')
        {
            if(decimalFound == true)
            {
                throw std::invalid_argument(error);
            }

            decimalFound = true;
        }
        // Throws all other possible inputted characters
        else
        {
            throw std::invalid_argument(error);
        }
    }
    
    // Checks if digits are present
    if(digitFound == false)
    {
        throw std::invalid_argument(error);
    }
    
    // Makes value negative if negative was found
    if(negativeFound == true)
    {
        value = -value;
    }

    // Check if final value is within the signed 16-bit range of −32768 to 32767
    if(value < -32768 || value > 32767)
    {
        throw std::invalid_argument(error);
    }

    return value;
}

int main() {
    std::string input;
    std::string repeat;
    
    // Runs at least once, loops again if answer to repeat was Y/y
    do
    {
        // Prompt user for string input
        std::cout << "Enter a String: ";
        std::cin >> input;
        std::cout << std::endl;
        
        try
        {
            // Convert value if possible using the function
            short result = ConvertToShort(input);
            std::cout << "Converted Value: " << result << std::endl;
        }
        
        catch(const std::exception& e)
        {
            // Print exception message if conversion failed
            std::cout << e.what() << std::endl;
        }
        
        // Input validation loop asking user if they want to convert another value
        do
        {
            std::cout << "Convert Another Value? (Y/y or N/n): ";
            std::cin >> repeat;
            std::cout << std::endl;
        }
        while(repeat != "Y" && repeat != "y" && repeat != "N" && repeat != "n");
    }
    while(repeat == "Y" || repeat == "y");
    
    return 0;
}
