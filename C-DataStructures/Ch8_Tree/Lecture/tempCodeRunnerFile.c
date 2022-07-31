int main(void)
{
	btree = insert_node( btree, 5 );
	btree = insert_node( btree, 4 );
	btree = insert_node( btree, 3 );
	btree = insert_node( btree, 2 );
	btree = insert_node( btree, 1 );

	inorder( btree );
	
	return 0;
}