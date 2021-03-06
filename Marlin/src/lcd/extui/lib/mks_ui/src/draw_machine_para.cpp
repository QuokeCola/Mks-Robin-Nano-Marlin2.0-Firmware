#include "../../../../../MarlinCore.h"
#if ENABLED(TFT_LITTLE_VGL_UI)
#include "lv_conf.h"
#include "../../../../../../Configuration.h"
#include "../inc/draw_ui.h"

static lv_obj_t * scr;

#define ID_PARA_RETURN			1

#define ID_PARA_MACHINE			2
#define ID_PARA_MACHINE_ARROW	3
#define ID_PARA_MOTOR			4
#define ID_PARA_MOTOR_ARROW		5
#define ID_PARA_ADVANCE			6
#define ID_PARA_ADVANCE_ARROW	7

static void event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch(obj->mks_obj_id)
	{
		case ID_PARA_RETURN:
	    if(event == LV_EVENT_CLICKED) {
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
			lv_clear_machine_para();
	        	draw_return_ui();
	    }
		break;
		case ID_PARA_MACHINE:
	    if(event == LV_EVENT_CLICKED) {
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
			lv_clear_machine_para();
	        	lv_draw_machine_settings();
	    }
		break;
		case ID_PARA_MACHINE_ARROW:
	    if(event == LV_EVENT_CLICKED) {
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
			lv_clear_machine_para();
	        	lv_draw_machine_settings();
	    }
		break;
		case ID_PARA_MOTOR:
	    if(event == LV_EVENT_CLICKED) {
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
			lv_clear_machine_para();
	        	lv_draw_motor_settings();
	    }
		break;
		case ID_PARA_MOTOR_ARROW:
	    if(event == LV_EVENT_CLICKED) {
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
			lv_clear_machine_para();
	        	lv_draw_motor_settings();
	    }
		break;
		case ID_PARA_ADVANCE:
	    if(event == LV_EVENT_CLICKED) {
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
			lv_clear_machine_para();
	        	lv_draw_advance_settings();
	    }
		break;
		case ID_PARA_ADVANCE_ARROW:
	    if(event == LV_EVENT_CLICKED) {
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
			lv_clear_machine_para();
	        	lv_draw_advance_settings();
	    }
		break;
	}
}

void lv_draw_machine_para(void)
{
	lv_obj_t *buttonBack,*label_Back;
	lv_obj_t *buttonMachine,*labelMachine,*buttonMachineNarrow;
	lv_obj_t *buttonMotor,*labelMotor,*buttonMotorNarrow;
	lv_obj_t *buttonAdvance,*labelAdvance,*buttonAdvanceNarrow;
	lv_obj_t * line1,* line2,* line3;
	if(disp_state_stack._disp_state[disp_state_stack._disp_index] != MACHINE_PARA_UI)
	{
		disp_state_stack._disp_index++;
		disp_state_stack._disp_state[disp_state_stack._disp_index] = MACHINE_PARA_UI;
	}
	disp_state = MACHINE_PARA_UI;

	scr = lv_obj_create(NULL, NULL);
	
	lv_obj_set_style(scr, &tft_style_scr);
  	lv_scr_load(scr);
  	lv_obj_clean(scr);

  	lv_obj_t * title = lv_label_create(scr, NULL);
	lv_obj_set_style(title, &tft_style_lable_rel);
	lv_obj_set_pos(title,TITLE_XPOS,TITLE_YPOS);
	lv_label_set_text(title, creat_title_text());
  
  	lv_refr_now(lv_refr_get_disp_refreshing());
	
	LV_IMG_DECLARE(bmp_para_back);
	LV_IMG_DECLARE(bmp_para_arrow);

	buttonMachine = lv_btn_create(scr, NULL);     /*Add a button the current screen*/
	lv_obj_set_pos(buttonMachine, PARA_UI_POS_X,PARA_UI_POS_Y);                            /*Set its position*/
	lv_obj_set_size(buttonMachine, PARA_UI_SIZE_X,PARA_UI_SIZE_Y);                          /*Set its size*/
	//lv_obj_set_event_cb(buttonMachine, event_handler); 
	lv_obj_set_event_cb_mks(buttonMachine, event_handler,ID_PARA_MACHINE,NULL,0);
	lv_btn_set_style(buttonMachine, LV_BTN_STYLE_REL, &tft_style_lable_rel);    /*Set the button's released style*/
	lv_btn_set_style(buttonMachine, LV_BTN_STYLE_PR, &tft_style_lable_pre);      /*Set the button's pressed style*/
	lv_btn_set_layout(buttonMachine, LV_LAYOUT_OFF);
	labelMachine = lv_label_create(buttonMachine, NULL);          /*Add a label to the button*/

	buttonMachineNarrow = lv_imgbtn_create(scr, NULL);
	lv_obj_set_pos(buttonMachineNarrow,PARA_UI_POS_X+PARA_UI_SIZE_X,PARA_UI_POS_Y+PARA_UI_ARROW_V);
	lv_obj_set_event_cb_mks(buttonMachineNarrow, event_handler,ID_PARA_MACHINE_ARROW,"bmp_arrow.bin",0);	
    	lv_imgbtn_set_src(buttonMachineNarrow, LV_BTN_STATE_REL, &bmp_para_arrow);
    	lv_imgbtn_set_src(buttonMachineNarrow, LV_BTN_STATE_PR, &bmp_para_arrow);	
	lv_imgbtn_set_style(buttonMachineNarrow, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonMachineNarrow, LV_BTN_STATE_REL, &tft_style_lable_rel);
	lv_btn_set_layout(buttonMachineNarrow, LV_LAYOUT_OFF);

	line1 = lv_line_create(scr, NULL);
	lv_ex_line(line1,line_points[0]);

	buttonMotor = lv_btn_create(scr, NULL);     /*Add a button the current screen*/
	lv_obj_set_pos(buttonMotor, PARA_UI_POS_X,PARA_UI_POS_Y*2);                            /*Set its position*/
	lv_obj_set_size(buttonMotor, PARA_UI_SIZE_X,PARA_UI_SIZE_Y);                          /*Set its size*/
	//lv_obj_set_event_cb(buttonMotor, event_handler); 
	lv_obj_set_event_cb_mks(buttonMotor, event_handler,ID_PARA_MOTOR,NULL,0);
	lv_btn_set_style(buttonMotor, LV_BTN_STYLE_REL, &tft_style_lable_rel);    /*Set the button's released style*/
	lv_btn_set_style(buttonMotor, LV_BTN_STYLE_PR, &tft_style_lable_pre);      /*Set the button's pressed style*/
	lv_btn_set_layout(buttonMotor, LV_LAYOUT_OFF);
	labelMotor = lv_label_create(buttonMotor, NULL);          /*Add a label to the button*/

	buttonMotorNarrow = lv_imgbtn_create(scr, NULL);
	lv_obj_set_pos(buttonMotorNarrow,PARA_UI_POS_X+PARA_UI_SIZE_X,PARA_UI_POS_Y*2+PARA_UI_ARROW_V);
	lv_obj_set_event_cb_mks(buttonMotorNarrow, event_handler,ID_PARA_MOTOR_ARROW,"bmp_arrow.bin",0);	
    	lv_imgbtn_set_src(buttonMotorNarrow, LV_BTN_STATE_REL, &bmp_para_arrow);
    	lv_imgbtn_set_src(buttonMotorNarrow, LV_BTN_STATE_PR, &bmp_para_arrow);	
	lv_imgbtn_set_style(buttonMotorNarrow, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonMotorNarrow, LV_BTN_STATE_REL, &tft_style_lable_rel);
	lv_btn_set_layout(buttonMotorNarrow, LV_LAYOUT_OFF);

	line2 = lv_line_create(scr, NULL);
	lv_ex_line(line2,line_points[1]);

	buttonAdvance = lv_btn_create(scr, NULL);     /*Add a button the current screen*/
	lv_obj_set_pos(buttonAdvance, PARA_UI_POS_X,PARA_UI_POS_Y*3);                            /*Set its position*/
	lv_obj_set_size(buttonAdvance, PARA_UI_SIZE_X,PARA_UI_SIZE_Y);                          /*Set its size*/
	//lv_obj_set_event_cb(buttonMotor, event_handler); 
	lv_obj_set_event_cb_mks(buttonAdvance, event_handler,ID_PARA_ADVANCE,NULL,0);
	lv_btn_set_style(buttonAdvance, LV_BTN_STYLE_REL, &tft_style_lable_rel);    /*Set the button's released style*/
	lv_btn_set_style(buttonAdvance, LV_BTN_STYLE_PR, &tft_style_lable_pre);      /*Set the button's pressed style*/
	lv_btn_set_layout(buttonAdvance, LV_LAYOUT_OFF);
	labelAdvance = lv_label_create(buttonAdvance, NULL);          /*Add a label to the button*/
	
	buttonAdvanceNarrow = lv_imgbtn_create(scr, NULL);
	lv_obj_set_pos(buttonAdvanceNarrow,PARA_UI_POS_X+PARA_UI_SIZE_X,PARA_UI_POS_Y*3+PARA_UI_ARROW_V);
	lv_obj_set_event_cb_mks(buttonAdvanceNarrow, event_handler,ID_PARA_ADVANCE_ARROW,"bmp_arrow.bin",0);	
    lv_imgbtn_set_src(buttonAdvanceNarrow, LV_BTN_STATE_REL, &bmp_para_arrow);
    lv_imgbtn_set_src(buttonAdvanceNarrow, LV_BTN_STATE_PR, &bmp_para_arrow);	
	lv_imgbtn_set_style(buttonAdvanceNarrow, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonAdvanceNarrow, LV_BTN_STATE_REL, &tft_style_lable_rel);
	lv_btn_set_layout(buttonAdvanceNarrow, LV_LAYOUT_OFF);

	line3 = lv_line_create(scr, NULL);
	lv_ex_line(line3,line_points[2]);

	buttonBack = lv_imgbtn_create(scr, NULL);
	lv_obj_set_event_cb_mks(buttonBack, event_handler,ID_PARA_RETURN,"bmp_back70x40.bin",0);	
    	lv_imgbtn_set_src(buttonBack, LV_BTN_STATE_REL, &bmp_para_back);
    	lv_imgbtn_set_src(buttonBack, LV_BTN_STATE_PR, &bmp_para_back);	
	lv_imgbtn_set_style(buttonBack, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonBack, LV_BTN_STATE_REL, &tft_style_lable_rel);

	lv_obj_set_pos(buttonBack,PARA_UI_BACL_POS_X,PARA_UI_BACL_POS_Y);
	lv_btn_set_layout(buttonBack, LV_LAYOUT_OFF);
	label_Back = lv_label_create(buttonBack, NULL);
	
	if(gCfgItems.multiple_language !=0)
	{
		lv_label_set_text(label_Back, common_menu.text_back);
		lv_obj_align(label_Back, buttonBack, LV_ALIGN_CENTER,0, 0);

		lv_label_set_text(labelMachine, MachinePara_menu.MachineSetting);
		lv_obj_align(labelMachine, buttonMachine, LV_ALIGN_IN_LEFT_MID,0, 0);

		lv_label_set_text(labelMotor, MachinePara_menu.MotorSetting);
		lv_obj_align(labelMotor, buttonMotor, LV_ALIGN_IN_LEFT_MID,0, 0);

		lv_label_set_text(labelAdvance, MachinePara_menu.AdvanceSetting);
		lv_obj_align(labelAdvance, buttonAdvance, LV_ALIGN_IN_LEFT_MID,0, 0);
	}

}

void lv_clear_machine_para()
{
	lv_obj_del(scr);
}
#endif