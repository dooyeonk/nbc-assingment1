#include <iostream>
#include <string>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 " << count << "개)" << endl;
}

void refillPotion(int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion += 1;
    *p_MPPotion += 1;
}

int main() {
    int hpIdx = 0;
    int mpIdx = 1;
    int powerIdx = 2;
    int armorIdx = 3;

    int stat[4] = {};

    while (true) {
        int hp;
        int mp;
        cout << "HP 와 MP를 입력해주세요: ";
        cin >> hp >> mp;

        if (hp > 50 && mp > 50) {
            stat[hpIdx] = hp;
            stat[mpIdx] = mp;

            break;
        }
        else {
            cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
        }
    }

    while (true) {
        int power;
        int armor;
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> power >> armor;

        if (power > 0 && armor > 0) {
            stat[powerIdx] = power;
            stat[armorIdx] = armor;

            break;
        }
        else {
            cout << "0 이하는 입력할 수 없습니다.";
        }
    }

    int hpPotion;
    int mpPotion;
    setPotion(5, &hpPotion, &mpPotion);

    cout << "==========================================" << endl;
    cout << "<스탯 관리 시스템>" << endl;
    cout << "1. HP UP" << endl;
    cout << "2. MP UP" << endl;
    cout << "3. 공격력 UP" << endl;
    cout << "4. 방어력 UP" << endl;
    cout << "5. 현재 능력치" << endl;
    cout << "6. level UP" << endl;
    cout << "0. 나가기" << endl;

    while (true) {
        int command;
        cout << "번호를 선택해주세요: ";
        cin >> command;

        if (command == 0) {
            break;
        }

        switch (command) {
        case 1:
            // HP 증가 (20)
            if (hpPotion > 0) {
                stat[hpIdx] += 20;
                cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
                cout << "현재 HP: " << stat[hpIdx] << endl;
                cout << "남은 포션 수 : " << --hpPotion << endl;
            }
            else {
                cout << "포션이 부족합니다." << endl;
            }
            break;
        case 2:
            // MP 증가 (20)
            if (mpPotion > 0) {
                stat[mpIdx] += 20;
                cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
                cout << "현재 MP: " << stat[mpIdx] << endl;
                cout << "남은 포션 수 : " << --mpPotion << endl;
            }
            else {
                cout << "포션이 부족합니다." << endl;
            }
            break;
        case 3:
            // 공격력 증가 (2배)
            stat[powerIdx] *= 2;
            cout << "* 공격력이 2배로 증가되었습니다." << endl;
            cout << "현재 공격력: " << stat[powerIdx] << endl;
            break;
        case 4:
            // 방어력 증가 (2배)
            stat[armorIdx] *= 2;
            cout << "* 방어력이 2배로 증가되었습니다." << endl;
            cout << "현재 방어력: " << stat[armorIdx] << endl;
            break;
        case 5:
            // 스텟 확인
            cout << "* HP : " << stat[hpIdx] << ", MP : " << stat[mpIdx] << ", 공격력 : " << stat[powerIdx] << ", 방어력 : " << stat[armorIdx] << endl;
            break;
        case 6:
            // 레벨업 포션 지급
            cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl;
            refillPotion(&hpPotion, &mpPotion);
            cout << "남은 HP/MP 포션 수 : " << hpPotion << "/" << mpPotion << endl;
            break;
        default:
            cout << "잘못된 명령입니다. 유효한 번호를 입력해주세요." << endl;
            break;
        }
    }

    cout << "프로그램을 종료합니다." << endl;

    return 0;
}