  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // Mac Lock (Leader -> q)
    SEQ_ONE_KEY(KC_Q) {
      SEND_STRING(SS_LCTRL(SS_LGUI("q")));
    }

    SEQ_ONE_KEY(KC_V) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " ");
      tap(KC_ENTER);
      SEND_STRING ("Built at: " QMK_BUILDDATE);
    }
    // git add
    SEQ_ONE_KEY(KC_A){
      SEND_STRING("git add ");
    }
    // git branch
    SEQ_ONE_KEY(KC_B){
      SEND_STRING("git branch ");
    }
    // git checkout
    SEQ_TWO_KEYS(KC_C, KC_O){
      SEND_STRING("git checkout ");
    }
    // git commit
    SEQ_ONE_KEY(KC_C){
      SEND_STRING("git commit -m \"\""SS_TAP(X_LEFT));
    }
    // git diff
    SEQ_ONE_KEY(KC_D){
      SEND_STRING("git diff ");
    }
    // git fetch
    SEQ_ONE_KEY(KC_F){
      SEND_STRING("git fetch ");
    }
    // git grep
    SEQ_ONE_KEY(KC_G){
      SEND_STRING("git grep ");
    }
    // git init
    SEQ_ONE_KEY(KC_I){
      SEND_STRING("git init");
    }
    // git log
    SEQ_ONE_KEY(KC_L){
      SEND_STRING("git log --decorate --oneline --graph");
    }
    // git merge
    SEQ_ONE_KEY(KC_M){
      SEND_STRING("git merge ");
    }
    // git mergetool
    SEQ_TWO_KEYS(KC_M, KC_T){
      SEND_STRING("git mergetool");
    }
    // git pull
    SEQ_TWO_KEYS(KC_P, KC_L){
      SEND_STRING("git pull ");
    }
    // git push
    SEQ_TWO_KEYS(KC_P, KC_S){
      SEND_STRING("git push ");
    }
    // git rebase
    SEQ_TWO_KEYS(KC_R, KC_B){
      SEND_STRING("git rebase ");
    }
    // git remote
    SEQ_ONE_KEY(KC_R){
      SEND_STRING("git remote ");
    }
    // git status
    SEQ_ONE_KEY(KC_S){
      SEND_STRING("git status ");
    }
    // git tag
    SEQ_ONE_KEY(KC_T){
      SEND_STRING("git tag ");
    }
  }
