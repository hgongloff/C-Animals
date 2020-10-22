
// Hunter Gongloff

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

char question[40][100];//Array of strings of the questions asked
char animals[40][100];//Array of strings of the animals used in the game
char response[100];//Responses given to the game
int j = 0;
int k = 2;//Keeps track of animals in array
int x = 1;

struct node
{ // Struct to define whats in a node
	char data[100];
	struct node* left;
	struct node* right;
};

struct node* newNode(char data[100])
{

	// Allocate memory for the new node
	struct node* node = (struct node*)malloc(sizeof(struct node));

	// Assign data to the node
	for (size_t i = 0; i < 100; i++)
	{
		node->data[i] = data[i];
	}

	// Set the new left and right nodes to NULL
	node->left = NULL;
	node->right = NULL;

	return(node);



}

void freeMemory(struct node* root)
{//Frees the memory used by the questions
	free(root);



}

struct node* newAnimal(struct node* root)
{//This functon creates a new animal and question to differentiate animal from others
	char oldAnimal[100];//old animal
	strcpy_s(oldAnimal, root->data);
	char newAnimal[100];//new animal to be added 
	int remove = 0;
	char answer[100];

	printf("I lose! What animal were you thinking of? \n > ");

	fgets(animals[k], sizeof(animals[k]), stdin);//Takes input of new animal into array

	strcpy_s(newAnimal, animals[k]);//Copies animal from array to newAnimal

	remove = strlen(newAnimal);
	if (newAnimal[remove - 1] == '\n')
	{
		newAnimal[remove - 1] = 0;
	}


	printf("Please give me a yes/no question that distinguishes between a %s and %s \n > ", oldAnimal, newAnimal);

	fgets(question[k], sizeof(question[k]), stdin);//Gets question to distinguish animals

	// update node
	root = newNode(question[k]);

	printf("Would the answer to this question be yes or no for a %s? \n > ", oldAnimal);

	fgets(answer, sizeof(answer), stdin);
	if (strcmp(answer, "yes\n") == 0)
	{//Sets oldAnimal to left branch and newAnimal to right branch
		root->left = newNode(oldAnimal);
		root->right = newNode(newAnimal);
	}
	else
	{//Sets oldAnimal to right branch and newAnimal to left branch
		root->left = newNode(newAnimal);
		root->right = newNode(oldAnimal);
	}

	strcpy_s(answer, "");
	printf("Thank you.  Would you like to play again? \n > ");

	fgets(answer, sizeof(answer), stdin);//finds out if user wants to play again

	if (strcmp(answer, "no\n") == 0)
	{
		freeMemory(root);
		exit(0);
	}
	printf("\n");
	strcpy_s(answer, "");
	k++;
	return(root);
}

struct node* inorder(struct node* root)
{//This function goes through the decision tree recursively to play the game
	if (root->left == NULL)
	{//If there are no more questions to ask in the decision tree other than if its a specific animal
		char animal[100];
		strcpy_s(animal, root->data);

		printf("Is it a %s?\n > ", animal);

		fgets(response, sizeof(response), stdin);

		if (strcmp(response, "yes\n") == 0)
		{//Computer wins if it guessed correct animal
			printf("I win!");
			printf("\n\n\n");
			freeMemory(root);
			exit(0);
		}
		else
		{
			strcpy_s(response, "");
			root = newAnimal(root);
			return(root);
		}
	}
	else
	{//If the computer has more questions to ask to narrow down what the animal is
		printf("%s > ", root->data);
		fgets(response, sizeof(response), stdin);

		if (strcmp(response, "yes\n") == 0)
		{
			if (root->left->left == NULL)
			{//Checks if next point is last in tree
				root->left = inorder(root->left);
				strcpy_s(response, "");
			}
			else
			{
				inorder(root->left);
				strcpy_s(response, "");
			}
		}
		else
		{
			if (root->right->right == NULL)
			{//Checks if next point is last in tree
				root->right = inorder(root->right);
				strcpy_s(response, "");
			}
			else
			{
				inorder(root->right);
				strcpy_s(response, "");
			}
		}
	}


}

int main()
{
	int numOfQuestions = 0;
	int remove = 0;

	strcpy_s(animals[0], "dog");

	printf("Is it a %s?\n > ", animals[0]);

	fgets(response, sizeof(response), stdin);//gets if computer has guessed the users animal

	if (strcmp(response, "yes\n") == 0)
	{//If the animal is a dog the computer wins
		printf("I win!");
		printf("\n\n\n");
		exit(0);
	}
	strcpy_s(response, "");
	printf("I lose! What animal were you thinking of? \n > ");

	fgets(animals[1], sizeof(animals[1]), stdin);//Gets what animal the user was thinking of

	// remove newline
	remove = strlen(animals[1]);
	if (animals[1][remove - 1] == '\n')
	{
		animals[1][remove - 1] = 0;
	}

	printf("Please give me a yes/no question that distinguishes between a dog and a %s. \n > ", animals[1]);

	fgets(question[0], sizeof(question[0]), stdin);//Gets yes/no question to distinguish animals

	// create root
	struct node* root = newNode(question[0]);
	// printf("%s", root->data);

	printf("Would the answer to this question be yes or no for a dog? \n > ");

	fgets(response, sizeof(response), stdin);
	if (strcmp(response, "yes\n") == 0)
	{//If the question applies to the dog
		root->left = newNode(animals[0]);
		root->right = newNode(animals[1]);
		strcpy_s(response, "");
	}
	else
	{//If the question does not apply to the dog
		root->left = newNode(animals[1]);
		root->right = newNode(animals[0]);
		strcpy_s(response, "");
	}

	printf("Thank you.  Would you like to play again? \n > ");

	fgets(response, sizeof(response), stdin);//gets if user wants to play again

	if (strcmp(response, "no\n") == 0)
	{//If the user wants to exit the game
		freeMemory(root);
		exit(0);
	}
	printf("\n");
	strcpy_s(response, "");

	while (numOfQuestions < 20)
	{//This while loop allows the game to play to up to 20 questions
		j = 0;
		inorder(root);
		numOfQuestions++;

	}


}


