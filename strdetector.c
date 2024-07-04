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
 *                  if (sd_check(&sd, str[i]))
 *                    cnt++;
 *                }
 *                printf("Number of detected string: %d", cnt);
 *
 *                return 0;
 *              }
 */
/* Define to prevent recursive inclusion ------------------------------ */
#include "strdetector.h"
#include <stdio.h>
/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */

uint32_t sd_init(strdetector_t *sd)
{
  if (sd == NULL)
    return SD_ERROR;
  sd->state = IDLE;
  return SD_SUCCESS;
}


uint32_t sd_reset(strdetector_t *sd)
{
  if (sd == NULL)
    return SD_ERROR;
  sd->state = IDLE;
  return SD_ERROR;
}


uint32_t sd_check(strdetector_t *sd, char c)
{
}

/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
