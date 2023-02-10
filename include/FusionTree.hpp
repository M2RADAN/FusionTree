#ifndef FUSIONTREE_HPP
#define FUSIONTREE_HPP

#define None -1

class FusionTree
{  
	public:
		/* поля fusion tree */

		unsigned int w;
		unsigned int r;

		/* узел */
		class Node
		{
			public:
				//поля узла
				bool isLeaf;

				long int* keys; // количество ключей
				Node** children; // кол-во ключей + 1 (как в б дереве)
				unsigned int key_count; // количество ключей

				long int m; // константа

				long int bs; // раздельные биты
				long int ms; // m_j биты

				long int sketches;
				long int sketch_maskl; //маска q
				long int sketch_maskh; //маска b

				long int b_mask;
				long int bm_mask;
					
				unsigned int sketch_gap;

				unsigned int r; // максимально количество ключей

				//методы узла..
				Node (unsigned int);

			

				void precompute (unsigned int);

				void info ();

				void merge (long int);

				void fill (long int);
		};

	Node* root;

	// примерные функции
	
	FusionTree ();

	~FusionTree ();
		
	void splitChild (Node*, int);

	void traverse (Node*);

	void traverse ();

	void init (Node*);

	void init ();

	void fill (Node*, long int);

	void removeFromLeaf (Node*, long int);

	void removeFromNonLeaf (Node*, long int);

	void remove (long int, Node*);

	void precompute (Node*);

	int parallelComparison (Node*, long int);

	long int getDiffBits (Node*);

	long int sketchApprox (Node*, long int);

	long int successor (Node*, long int);

	long int successor (long int);

	long int predecessor (Node*, long int);

	long int predecessor (long int);

	long int get_m_bits (long int);

	Node* lookUp (long int, Node*);

	Node* insertNormal (Node*, long int);

	Node* insert (long int);

	//статика

	static long int get_m (long int);

	static long int getMask (long int);

	static long int getComboMask (long int, long int);
}; 

#endif
