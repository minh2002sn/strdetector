/**
 * @file        strdetect.h
 * @copyright
 * @license
 * @version     0.0.0
 * @date        07/03/2024
 * @author      Minh Phung Nhat
 *              Hung Pham Duc
 *              Khoi Nguyen Thanh
 * @brief       String "10110" detect
 *
 * @note        none
 *
 * @example
 *              #include <stdio.h>
 *              #include <stdint.h>
 *              #include "strdetector.h"
 *
 *              int main()
 *              {
 *                char str[]   = "1010110ABC10110110";
 *                uint32_t cnt = 0;
 *                strdetector_t sd;
 *                sd_init(&sd);
 *                for (int i = 0; i < sizeof(str) - 1; i++)
 *                {
 *                  if (sd_char_check(&sd, str[i]))
 *                  cnt++;
 *                }
 *                printf("Number of detected string: %d\n", cnt);
 *
 *                sd_reset(&sd);
 *                printf("Number of detected string: %d\n", sd_str_check(&sd, str, sizeof(str) - 1));
 *
 *                return 0;
 *              }
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __STRDETECT_H
#define __STRDETECT_H

/* Includes ----------------------------------------------------------- */
#include <stdint.h>

/* Public defines ----------------------------------------------------- */
#define SD_ERROR   (0x00000000) /* Error return vale */
#define SD_SUCCESS (0x00000001) /* Success return vale */

/* Public enumerate/structure ----------------------------------------- */

enum state_enum
{
  IDLE = 0,
  S0_1XXXX,
  S1_10XXX,
  S2_101XX,
  S3_1011X,
  S4_10110,
};
typedef struct
{
  enum state_enum state;
} strdetector_t;

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/* Public function prototypes ----------------------------------------- */
/**
 * @brief           Initialize string detector
 *
 * @param[in]       sd      Pointer to a strdetector_t structure
 *
 * @return
 *  - (1) : Success
 *  - (0) : Error
 */
uint32_t sd_init(strdetector_t *sd);

/**
 * @brief           Reset string detector
 *
 * @param[in]       sd      Pointer to a strdetector_t structure
 *
 * @return
 *  - (1) : Success
 *  - (0) : Error
 */
uint32_t sd_reset(strdetector_t *sd);

/**
 * @brief           Check whether string "10110" appeared, check single char
 *
 * @param[in]       sd      Pointer to a cbuffer_t structure
 * @param[in]       c       Input char
 *
 * @return
 *  - (1) : String "10110" is detected
 *  - (0) : String "10110" is not detected
 */
uint32_t sd_char_check(strdetector_t *sd, char c);

/**
 * @brief           Check whether string "10110" appeared, check a string
 *
 * @param[in]       sd      Pointer to a cbuffer_t structure
 * @param[in]       str     Pointer to string buffer
 * @param[in]       size    Pointer to string buffer
 *
 * @return          Number of "10110" string detected
 */
uint32_t sd_str_check(strdetector_t *sd, char *str, uint32_t size);


#endif // __STRDETECT_H

/* End of file -------------------------------------------------------- */
