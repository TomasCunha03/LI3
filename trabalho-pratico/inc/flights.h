#ifndef flights_h
#define flights_h

typedef struct flight FLIGHT;

FLIGHT *new_Flight(char *line);

void kill_flight(void *flight);

char *getID_flight(FLIGHT *f);
char *getAirline(FLIGHT *f);
char *getPlaneModel(FLIGHT *f);
int getTotalSeats(FLIGHT *f);
char *getFlightOrigin(FLIGHT *f);
char *getFlightDestination(FLIGHT *f);
char *getScheduleDepartureDate(FLIGHT *f);
char *getScheduleArrivalDate(FLIGHT *f);
char *getRealDepartureDate(FLIGHT *f);
char *getRealArrivalDate(FLIGHT *f);
char *getPilot(FLIGHT *f);
char *getCopilot(FLIGHT *f);
char *getNotes(FLIGHT *f);

#endif