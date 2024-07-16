#ifndef BUZZER_H 
    #define BUZZER_H

    extern bool buzzer_enabled;
    extern unsigned long last_tone_toggle;
    extern uint16_t buzzer_delay;
    extern uint16_t last_buzzer_tone;

    void update_buzzer_tone(uint16_t hi_tone, uint16_t lo_tone) {
        if (buzzer_enabled) {
            if (millis() - last_tone_toggle >= buzzer_delay) {
                if (last_buzzer_tone == RX_HI_TONE) {
                    tone(PIN_BUZZER, RX_LO_TONE);
                    last_buzzer_tone = RX_LO_TONE;
                } else {
                    tone(PIN_BUZZER, RX_HI_TONE);
                    last_buzzer_tone = RX_HI_TONE;
                }
                buzzer_delay = ::random(MAX_BUZZER_DELAY);
                last_tone_toggle = millis();
            }
        }
    }

    void update_buzzer_notone() {
      if (buzzer_enabled) {
          if (millis() - last_tone_toggle >= buzzer_delay) {
              noTone(PIN_BUZZER);
              digitalWrite(PIN_BUZZER, LOW);
          }
      }
    }

    void toggle_buzzer_enable() {
        buzzer_enabled = !buzzer_enabled;
        update_buzzer_notone();
    }
#endif
