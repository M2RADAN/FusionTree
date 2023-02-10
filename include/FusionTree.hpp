#ifndef FUSIONTREE_HPP
#define FUSIONTREE_HPP

#define None -1

class FusionTree
{  
	public:
		/* ���� fusion tree */

		unsigned int w;
		unsigned int r;

		/* ���� */
		class Node
		{
			public:
				//���� ����
				bool isLeaf;

				long int* keys; // ���������� ������
				Node** children; // ���-�� ������ + 1 (��� � � ������)
				unsigned int key_count; // ���������� ������

				long int m; // ���������

				long int bs; // ���������� ����
				long int ms; // m_j ����

				long int sketches;
				long int sketch_maskl; //����� q
				long int sketch_maskh; //����� b

				long int b_mask;
				long int bm_mask;
					
				unsigned int sketch_gap;

				unsigned int r; // ����������� ���������� ������

				//������ ����..
				Node (unsigned int);

			

				void precompute (unsigned int);

				void info ();

				void merge (long int);

				void fill (long int);
		};

	Node* root;

	// ��������� �������
	
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

	//�������

	static long int get_m (long int);

	static long int getMask (long int);

	static long int getComboMask (long int, long int);
}; 

#endif
