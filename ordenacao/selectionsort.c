public static void selectionSort(int[] v) {	
	for (int i = 0; i < v.length; i++) {
		
		int i_menor = i;
		for (int j = i + 1; j < v.length; j++)
			if (v[j] < v[i_menor])
				i_menor = j;
		
		int aux = v[i];
		v[i] = v[i_menor];
		v[i_menor] = aux;
	
	}		
}