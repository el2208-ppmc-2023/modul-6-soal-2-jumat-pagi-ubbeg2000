/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               :
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Struct Node Linked List
struct Node
{
	int data;
	struct Node *next;
} Node;

void push(struct Node **head, int new_data)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;

	// Kondisi ketika linked list kosong
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	// Kondisi ketika data baru menggantikan head linked list
	if ((*head)->data > new_data)
	{
		new_node->next = *head;
		*head = new_node;
		return;
	}

	// Kondisi ketika linked list hanya berisi satu elemen
	// dan data baru harus dimasukin di akhir linked list
	if ((*head)->data < new_data && (*head)->next == NULL)
	{
		(*head)->next = new_node;
		return;
	}

	struct Node *cur = *head;
	while (cur->next != NULL)
	{
		if (cur->next->next == NULL)
		{
			if (cur->next->data < new_data)
			{
				cur->next->next = new_node;
				return;
			}
			else
			{
				new_node->next = cur->next;
				cur->next = new_node;
				return;
			}
		}

		if (cur->next->data < new_data)
		{
			cur = cur->next;
		}
		else
		{
			new_node->next = cur->next;
			cur->next = new_node;
			break;
		}
	}
}

int main()
{
	// Deklarasi variabel-variabel
	struct Node *linked_list = NULL;
	struct Node *cur = NULL;
	int n, v, i;

	// input linked list pertama
	printf("Berapa Kali David Lari Pada Minggu 1: ");
	scanf("%d", &n);

	printf("Masukkan Jarak Yang Ditempuh Pada Minggu 1(meter): ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v);
		push(&linked_list, v);
	}

	// input linked list kedua
	printf("Berapa Kali David Lari Pada Minggu 2: ");
	scanf("%d", &n);

	printf("Masukkan Jarak Yang Ditempuh Pada Minggu 2(meter): ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v);
		push(&linked_list, v);
	}

	// input linked list ketiga
	printf("Berapa Kali David Lari Pada Minggu 3: ");
	scanf("%d", &n);

	printf("Masukkan Jarak Yang Ditempuh Pada Minggu 3(meter): ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v);
		push(&linked_list, v);
	}

	// cetak hasil
	printf("\nJarak David Berlari Dari Kecil Ke Besar:\n");
	cur = linked_list;
	while (cur != NULL)
	{
		printf("%d meter\n", cur->data);
		cur = cur->next;
	}

	return 0;
}
