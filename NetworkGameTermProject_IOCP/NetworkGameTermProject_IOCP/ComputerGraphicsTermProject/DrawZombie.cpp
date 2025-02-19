#include "main.h"

//void drawZombie(Player_Socket *player_socket, bool sight, int zombie_up_state, float right_leg_x, float right_leg_z, float left_leg_x, float left_leg_z, float right_knee_x, float left_knee_x)
void drawZombie(Player_Socket *player_socket, Player_Animation *Ani)
{
	glPushMatrix();//�׸��� ��ŸƮ
	glTranslated(player_socket->x, player_socket->y + 140, player_socket->z);//
	glRotatef(player_socket->camxrotate + 180, 0, 1, 0);

	bool a = false;//���̵�����
	drawGun(player_socket, a );//�ѱ׸���

	glPushMatrix(); //Save �Ӹ�
	glTranslated(0, 75, 0);
	glRotatef(-(player_socket->camyrotate + 90) / 3, 1, 0, 0);
	glScaled(1.0, 1.0, 0.7);
	drawBoxFront(30, false, zombie_head_object[0]);
	drawBoxBack(30, false, zombie_head_object[1]);
	drawBoxLeft(30, false, zombie_head_object[2]);
	drawBoxRight(30, false, zombie_head_object[3]);
	drawBoxTop(30, false, zombie_head_object[4]);
	drawBoxBottom(30, false, zombie_head_object[5]);
	glPopMatrix(); //�Ӹ� end

	glPushMatrix(); //Save ����
	glScaled(1.0, 1.5, 0.5);
	drawBoxFront(30, false, zombie_body_object[0]);
	drawBoxBack(30, false, zombie_body_object[1]);
	drawBoxLeft(30, false, zombie_body_object[2]);
	drawBoxRight(30, false, zombie_body_object[3]);
	drawBoxTop(30, false, zombie_body_object[4]);
	drawBoxBottom(30, false, zombie_body_object[5]);
	glPopMatrix(); //���� end


	if (Ani->sight) {}
	else
	{
		if (Ani->character_up_state == CHARACTER_PISTOL)
		{
			glPushMatrix(); //Save ������ �
			glTranslated(-45, 44, 0);
			glRotatef(-player_socket->camyrotate + 210, 1, 0, 0);
			glRotatef(30, 0, 1, 0);
			glRotatef(0, 0, 0, 1);
			glScaled(0.5, 0.75, 0.5);
			drawBoxFront(30, true, zombie_arm_top_object[0]);
			drawBoxBack(30, true, zombie_arm_top_object[1]);
			drawBoxLeft(30, true, zombie_arm_top_object[2]);
			drawBoxRight(30, true, zombie_arm_top_object[3]);
			drawBoxTop(30, true, zombie_arm_top_object[4]);
			drawBoxBottom(30, true, zombie_arm_top_object[5]);
			glScaled(2, 1.333333, 2);

			glPushMatrix(); //Save ������ �Ȳ�ġ
			glTranslated(0, -45, 0);
			glRotatef(-30, 1, 0, 0);
			glPushMatrix();
			glScaled(0.5, 0.75, 0.5);
			drawBoxFront(30, true, zombie_arm_bottom_object[0]);
			drawBoxBack(30, true, zombie_arm_bottom_object[1]);
			drawBoxLeft(30, true, zombie_arm_bottom_object[2]);
			drawBoxRight(30, true, zombie_arm_bottom_object[3]);
			drawBoxTop(30, true, zombie_arm_top_object[5]);
			drawBoxBottom(30, true, zombie_arm_top_object[5]);
			glPopMatrix();
			glPopMatrix();//������ �Ȳ�ġ ����
			glPopMatrix();//������ � ����


			glPushMatrix(); //Save ���� � 
			glTranslated(45, 44, 0);
			glRotatef(-player_socket->camyrotate - 90, 1, 0, 0);
			glRotatef(70, 0, 1, 0);
			glRotatef(-75, 0, 0, 1);
			glScaled(0.5, 0.75, 0.5);
			drawBoxFront(30, true, zombie_arm_top_object[0]);
			drawBoxBack(30, true, zombie_arm_top_object[1]);
			drawBoxLeft(30, true, zombie_arm_top_object[2]);
			drawBoxRight(30, true, zombie_arm_top_object[3]);
			drawBoxTop(30, true, zombie_arm_top_object[4]);
			drawBoxBottom(30, true, zombie_arm_top_object[5]);
			glScaled(2, 1.333333, 2);

			glPushMatrix(); //Save ���� �Ȳ�ġ
			glTranslated(0, -45, 0);
			glRotatef(25, 1, 0, 0);
			glScaled(0.5, 0.75, 0.5);
			drawBoxFront(30, true, zombie_arm_bottom_object[0]);
			drawBoxBack(30, true, zombie_arm_bottom_object[1]);
			drawBoxLeft(30, true, zombie_arm_bottom_object[2]);
			drawBoxRight(30, true, zombie_arm_bottom_object[3]);
			drawBoxTop(30, true, zombie_arm_top_object[5]);
			drawBoxBottom(30, true, zombie_arm_top_object[5]);
			glPopMatrix();//���� �Ȳ�ġ ����
			glPopMatrix();//���Ⱦ ����
		}
		else if (Ani->character_up_state == CHARACTER_NOWEAPON)
		{
			glPushMatrix(); //Save ������ �
			glTranslated(-45, 44, 0);
			glScaled(0.5, 0.75, 0.5);
			drawBoxFront(30, true, zombie_arm_top_object[0]);
			drawBoxBack(30, true, zombie_arm_top_object[1]);
			drawBoxLeft(30, true, zombie_arm_top_object[2]);
			drawBoxRight(30, true, zombie_arm_top_object[3]);
			drawBoxTop(30, true, zombie_arm_top_object[4]);
			drawBoxBottom(30, true, zombie_arm_top_object[5]);
			glScaled(2, 1.333333, 2);

			glPushMatrix(); //Save ������ �Ȳ�ġ
			glTranslated(0, -45, 0);
			glPushMatrix();
			glScaled(0.5, 0.75, 0.5);
			drawBoxFront(30, true, zombie_arm_bottom_object[0]);
			drawBoxBack(30, true, zombie_arm_bottom_object[1]);
			drawBoxLeft(30, true, zombie_arm_bottom_object[2]);
			drawBoxRight(30, true, zombie_arm_bottom_object[3]);
			drawBoxTop(30, true, zombie_arm_top_object[5]);
			drawBoxBottom(30, true, zombie_arm_top_object[5]);
			glPopMatrix();
			glPopMatrix();//������ �Ȳ�ġ ����
			glPopMatrix();//������ � ����


			glPushMatrix(); //Save ���� � 
			glTranslated(45, 44, 0);
			glScaled(0.5, 0.75, 0.5);
			drawBoxFront(30, true, zombie_arm_top_object[0]);
			drawBoxBack(30, true, zombie_arm_top_object[1]);
			drawBoxLeft(30, true, zombie_arm_top_object[2]);
			drawBoxRight(30, true, zombie_arm_top_object[3]);
			drawBoxTop(30, true, zombie_arm_top_object[4]);
			drawBoxBottom(30, true, zombie_arm_top_object[5]);
			glScaled(2, 1.333333, 2);

			glPushMatrix(); //Save ���� �Ȳ�ġ
			glTranslated(0, -45, 0);
			glScaled(0.5, 0.75, 0.5);
			drawBoxFront(30, true, zombie_arm_bottom_object[0]);
			drawBoxBack(30, true, zombie_arm_bottom_object[1]);
			drawBoxLeft(30, true, zombie_arm_bottom_object[2]);
			drawBoxRight(30, true, zombie_arm_bottom_object[3]);
			drawBoxTop(30, true, zombie_arm_top_object[5]);
			drawBoxBottom(30, true, zombie_arm_top_object[5]);
			glPopMatrix();//���� �Ȳ�ġ ����
			glPopMatrix();//���Ⱦ ����
		}
	}


	glPushMatrix(); //Save ������ ���
	glTranslated(-15, -40, 0);
	glRotatef(Ani->right_leg_x, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(Ani->right_leg_z, 0, 0, 1);
	glScaled(0.5, 0.75, 0.5);
	drawBoxFront(30, true, zombie_leg_top_object[0]);
	drawBoxBack(30, true, zombie_leg_top_object[1]);
	drawBoxLeft(30, true, zombie_leg_top_object[2]);
	drawBoxRight(30, true, zombie_leg_top_object[3]);
	drawBoxTop(30, true, zombie_leg_top_object[4]);
	drawBoxBottom(30, true, zombie_leg_top_object[5]);
	glScaled(2, 1.333333, 2);

	glPushMatrix(); //Save ������ ����
	glTranslated(0, -45, 0);
	glRotatef(Ani->right_knee_x, 1, 0, 0);
	glScaled(0.5, 0.75, 0.5);
	drawBoxFront(30, true, zombie_leg_bottom_object[0]);
	drawBoxBack(30, true, zombie_leg_bottom_object[1]);
	drawBoxLeft(30, true, zombie_leg_bottom_object[2]);
	drawBoxRight(30, true, zombie_leg_bottom_object[3]);
	drawBoxTop(30, true, zombie_leg_top_object[4]);
	drawBoxBottom(30, true, zombie_leg_top_object[5]);
	glPopMatrix();//������ ���� ����

	glPopMatrix();//������ ��� ����


	glPushMatrix(); //Save ���� ���
	glTranslated(15, -40, 0);
	glRotatef(Ani->left_leg_x, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(Ani->left_leg_z, 0, 0, 1);
	glScaled(0.5, 0.75, 0.5);
	drawBoxFront(30, true, zombie_leg_top_object[0]);
	drawBoxBack(30, true, zombie_leg_top_object[1]);
	drawBoxLeft(30, true, zombie_leg_top_object[2]);
	drawBoxRight(30, true, zombie_leg_top_object[3]);
	drawBoxTop(30, true, zombie_leg_top_object[4]);
	drawBoxBottom(30, true, zombie_leg_top_object[5]);
	glScaled(2, 1.333333, 2);

	glPushMatrix(); //Save ���� ����
	glTranslated(0, -45, 0);
	glRotatef(Ani->left_knee_x, 1, 0, 0);
	glScaled(0.5, 0.75, 0.5);
	drawBoxFront(30, true, zombie_leg_bottom_object[0]);
	drawBoxBack(30, true, zombie_leg_bottom_object[1]);
	drawBoxLeft(30, true, zombie_leg_bottom_object[2]);
	drawBoxRight(30, true, zombie_leg_bottom_object[3]);
	drawBoxTop(30, true, zombie_leg_top_object[4]);
	drawBoxBottom(30, true, zombie_leg_top_object[5]);
	glPopMatrix(); //���� ���� ����

	glPopMatrix(); //���ʰ�� ����

	glPopMatrix(); //�׸��� ����
}


void init_Zombie_Texture() {
	zombie_head_Texture(zombie_head_object);
	zombie_body_Texture(zombie_body_object);
	zombie_arm_Texture(zombie_arm_top_object, zombie_arm_bottom_object);
	zombie_leg_Texture(zombie_leg_top_object, zombie_leg_bottom_object);
}