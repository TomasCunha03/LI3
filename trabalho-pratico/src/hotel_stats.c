#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#include "../inc/hotel_stats.h"


struct h_stat{
    char *hotelid;
    double nReservas;
    double somaRatings;
    double avgscore;
    GList *reservasHotel;
};

void kill_hotelStat(void *hotelStat){
	HOTEL_STAT *hs = hotelStat;
	
	free(hs->hotelid);

	/*while(hs->reservasHotel != NULL){
		RESERVATION *reserva = (RESERVATION *)hs->reservasHotel->data;

		kill_reservation(reserva);

		hs->reservasHotel = g_list_delete_link(hs->reservasHotel,hs->reservasHotel);
	}*/

	free(hs);
}

// FUNÇÕES GET

char *get_hotel_stat_id(HOTEL_STAT *h)
{
	return strdup(h->hotelid);
}
double get_hotel_stat_nReservas(HOTEL_STAT *h)
{
	return h->nReservas;
}

double get_hotel_stat_somaRatings(HOTEL_STAT *h)
{
	return h->somaRatings;
}

double get_hotel_stat_avgscore(HOTEL_STAT *h){
	return h->avgscore;
}

GList *get_hotel_stat_reservasHotel(HOTEL_STAT *h)
{
	return h->reservasHotel;
}


void create_hotel_stats(RESERVATION *r, GHashTable *hotel_stats)
{
	char *hotelID = getHotelID_reservation(r);	
	
	HOTEL_STAT *hstat = g_hash_table_lookup(hotel_stats, hotelID);
    double rating = getRating_reservation(r);
		if (hstat == NULL)
		{
			HOTEL_STAT *hotel_stat = malloc(sizeof(HOTEL_STAT));
            
			hotel_stat->hotelid = hotelID;
            hotel_stat->nReservas = 1;
            hotel_stat->somaRatings = rating;
			hotel_stat->avgscore = rating;
            hotel_stat->reservasHotel = g_list_append(NULL,r);
			g_hash_table_insert(hotel_stats, hotelID, hotel_stat);
		}
		else{

			hstat->nReservas += 1;
            hstat->somaRatings += rating;
            hstat->avgscore = hstat->somaRatings/hstat->nReservas;
            hstat->reservasHotel = g_list_append(hstat->reservasHotel,r);
			free(hotelID);
        }
		
}

