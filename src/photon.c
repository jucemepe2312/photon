/*
 * photon.c - Benchmark de CPU y disco en C
 * Copyright (C) 2026 Julio <jucemepe2312@gmail.com>
 *
 * Este programa es software libre: puedes redistribuirlo y/o modificarlo
 * bajo los términos de la GNU General Public License publicada por la
 * Free Software Foundation, ya sea la versión 3 de la Licencia, o
 * (a tu elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; ni siquiera la garantía implícita de
 * COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR. Véase la
 * GNU General Public License para más detalles.
 *
 * Deberías haber recibido una copia de la GNU General Public License
 * junto con este programa. Si no, consulta <https://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
unsigned long long num_operaciones;
void medir_disco()
{
    struct timespec inicio, fin;
    int fd = open("test.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open");
        return;
    }

    char buffer[1024 * 1024];

    clock_gettime(CLOCK_MONOTONIC, &inicio);

    for (int i = 0; i < 500; i++)
    {
        if (write(fd, buffer, sizeof(buffer)) != sizeof(buffer))
        {
            perror("write");
            close(fd);
            return;
        }
    }

    fsync(fd);

    clock_gettime(CLOCK_MONOTONIC, &fin);
    close(fd);
    unlink("test.bin");

    double tiempo = (fin.tv_sec - inicio.tv_sec) +(fin.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tiempo: %.4f segundos\n", tiempo);
    printf("Velocidad: %.2f MB/s\n", 500.0 / tiempo);
}

int medir_cpu(unsigned long long num_operaciones)
{
    struct timespec inicio, fin;
    clock_gettime(CLOCK_MONOTONIC, &inicio);

    volatile unsigned long long resultado = 1;
    for (int i = 0; i < num_operaciones; i++)
    {

        resultado = resultado * 3 + 1;
    }

    clock_gettime(CLOCK_MONOTONIC, &fin);
    double tiempo = (fin.tv_sec - inicio.tv_sec) +(fin.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tiempo: %.6f segundos\n", tiempo);
    printf("%llu\n", resultado);
    return 0;
}

int main(void)

{
    printf("Bienvenido a Photon Benchmark\n");
    printf("elige que quieres hacer\n 1. medir cpu\n 2. medir disco\n");
    int opcion;
    scanf("%d", &opcion);
    if (opcion == 1)
    {

        printf("introduce el numero de operaciones que debera realizar el benchmark\n");
        scanf("%llu", &num_operaciones);
        if (num_operaciones > 0)
        {
            medir_cpu(num_operaciones);
        }
        else
        {
            printf("error \n");
        }

    }
    else if (opcion == 2)
    {
        medir_disco();
    }
    else
    {
        printf("opcion incorrecta\n");
    }

    return 0;
}