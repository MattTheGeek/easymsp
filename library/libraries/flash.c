void flashNuke(unsigned short int key1, unsigned short int key2)
{
	unsigned short int key = (~(0xF00D) & (key1 ^ key2));
}
