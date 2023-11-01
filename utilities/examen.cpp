#include <iostream>
#include <vector>
using namespace std;
struct FVector
{
    float x;
    float y;
    float z;
};
struct FRotator
{
    float yaw;
    float blabla;
    float blibli;
};
class Actor
{
    public:
    FVector posicion;
};
class Balin : public Actor
{

};
class Player: public Actor
{
    public:
    
    Player()
    {
        posicion.x = posicion.y = posicion.z = 0;
    }
    void jump()
    {

    }
    void avanzar(float dx)
    {
        //implementa la funcionalidad de avanzar
        //el personaje siempre avanza dx a la derecha
        posicion.x = posicion.x + dx*3;
        
    }
    void esquivar(Balin b)
    {
        //el metodo debe permitir  moverse hacia abajo un carrill considerando que el balin
        //ya se encuentra a una distancia de al menos 2 unidades

    }

    int calcularDistancia(Balin b)
    {
        //el balin siempre estara en el mismo carril
        //si no fuese el caso, la distancia se asume que es cero
        return 0;
    }

    vector<Balin> getBalinesMismoCarril(vector<Balin> balines)
    {
        vector<Balin> subconjunto;
        //dada una lista de los balines en la escena, crea un subconjunto
        // de todos los balines que estan en el mismo carril del player
        //devuelve ese subconjunto en el metodo
        return subconjunto;
    }

    Balin obtenerBalinMasCercanoEnCarril(vector<Balin> balines)
    {
        Balin cercano;
        //retorna el balin mas cercano que esta en el mismo carril del player
        return cercano;
    }
};
void printPlayerPosition(Player p)
{
    cout<<p.posicion.x<<" "<<p.posicion.y<<" "<<p.posicion.z<<endl;
}
int main()
{
    FVector posicion;
    FRotator rotacion;
    Player jug;
    for(int i=0; i<10; i++)
    {
        //jug.avanzar(i);
    }
    cout<< "posiion final"<<endl;    //90 0 0
    printPlayerPosition(jug);

    Balin b1,b2,b3;
    jug.esquivar(b1);
    jug.esquivar(b2);
    jug.esquivar(b3);
    printPlayerPosition(jug);    //0 -2 0

    return 0;
}