#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

//class definition
class Food {
public:
    std::string name;
    char type;

    Food(std::string name, char type) : name(name), type(type) {}
};

void print(std::vector<Food>& items) {
	//output
    for(const auto& item : items)
        std::cout<<item.name<<" ";
    std::cout<<std::endl;
}

void partition(std::vector<Food>& items, int left, int right) {
	//base case
	if(left >= right)
		return;
	
    //find the first vegetable from left
    while(left <= right && items[left].type != 'v')
        left++;

	//find the first fruit from right
    while(left <= right && items[right].type != 'f')
        right--;

    //if the first vegetable found (left) is before the first fruit found (right), the two are in the wrong order, hence swap
    if(left < right) {
    	//swap 
	    std::swap(items[left], items[right]);
	    //narrow the bounds of the array, so that a smaller part is considered the next time a recursion happens
	    left++;
	    right--;
	
	    //recursion, with the array being "smaller"
	    std::cout<<"	subarray indexes: "<<left<<" | "<<right<<std::endl;
	    partition(items, left, right);
	}
	//otherwise do nothing, no swap needed
}

int main() {
	//predefined lists (in a more advanced version these could be a database)
    std::unordered_set<std::string> fruits = {"apple", "banana", "orange", "strawberry", "kiwi"};
    std::unordered_set<std::string> vegetables = {"tomato", "carrot", "spinach", "cucumber"};
	
	//input
    std::vector<std::string> input = {"carrot", "tomato", "apple", "spinach", "strawberry", "kiwi", "carrot", "tomato", "apple", "spinach", "strawberry", "kiwi"};
	
	std::vector<Food> items;
	//classification
	for(const auto& element : input)
        if(fruits.count(element)) //if the element is a fruit
            items.emplace_back(element, 'f'); //mark as fruit
		else if(vegetables.count(element)) //or, if the element is part of vegetables
            items.emplace_back(element, 'v'); //mark it as such

	//sorting
    partition(items, 0, items.size() - 1);

	//output
    print(items);

    return 0;
}
