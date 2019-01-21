//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "interface.h"
#include "rossler.h" // incluindo a classe da thread
#include <stdio.h>
#include "logpixels.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
TWCRun *WCRun;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

int seg_objc;

char *doubletostr(double dnum)
{
	char *tchar;
	tchar = (char *) malloc(20);
	sprintf(tchar,"%.3f",dnum);
	return tchar;
}

void __fastcall PaintImage()
{
	//int c;
	double c;
	for(int i=0;i<Form1->Image1->Picture->Width;i++)
		for(int j=0;j<Form1->Image1->Picture->Height;j++)
		{
			c = int((WCRun->x[i+1][j+1]+25)*5);
			//c = int(WCRun->att_contrast[i+1][j+1]*255);
			Form1->ImageSegmented->Picture->Bitmap->Canvas->Pixels[i][j] = c + 256*c + 65536*c;
			//c = WCRun->img_obj[i+1][j+1];
			//Form1->ImageSegmented->Picture->Bitmap->Canvas->Pixels[i][j] = 65536*((c%4)*85) + 256*((c/4%4)*85) + ((c/4/4%4)*85);
		 }
}

void __fastcall UpdateLabels()
{
	Form1->lblt->Caption = doubletostr(WCRun->t);
	Form1->lblExeTime->Caption = doubletostr((WCRun->clock_end - WCRun->clock_start) / CLK_TCK);
	if (Form1->CheckBoxShowBehavior->Checked) PaintImage();

	/*
	if (WCRun->paint)
	{
		seg_objc = WCRun->seg_objc;
		Form1->lblSegObj->Caption = seg_objc+1;
		PaintImage();
		WCRun->paint=false;
	}
	if (WCRun->seg_done) Form1->lblSegmentationDone->Visible = true;
	*/
	/*
	for(int i=0;i<Form1->Image1->Picture->Width;i++)
		for(int j=0;j<Form1->Image1->Picture->Height;j++)
			Form1->StringGrid1->Cells[i][j] = WCRun->image[i+1][j+1];
	*/
}

void __fastcall TForm1::btnRunClick(TObject *Sender)
{
	seg_objc=0;
	ImageSegmented->Picture->Bitmap = Image1->Picture->Bitmap;
	ImageSegmented->Picture->Bitmap->Monochrome = false;
	//StringGrid1->ColCount = Image1->Picture->Width;
	//StringGrid1->RowCount = Image1->Picture->Height;
	WCRun = new TWCRun(true);
	WCRun->FreeOnTerminate = true;
	WCRun->OnTerminate = WCRunHandleTerminate;
	WCRun->k = edtk->Text.ToDouble();
	WCRun->t_step = edtt_step->Text.ToDouble();
	WCRun->t_start = edtt_start->Text.ToDouble();
	WCRun->t_segment = edtt_segment->Text.ToDouble();
	WCRun->t_record = edtt_record->Text.ToDouble();
	WCRun->t_record_end = EditStopLoggingTime->Text.ToDouble();
	WCRun->logging = cbLogging->Checked;
	WCRun->logging_end = CheckBoxStopLoggingTime->Checked;
	WCRun->t_end = edtt_end->Text.ToDouble();
	WCRun->cplimit = edtlimiar->Text.ToInt();
	WCRun->sal_exp = edtSalExp->Text.ToDouble();
	WCRun->delta_omega = edtDeltaOmega->Text.ToDouble();
	WCRun->seg_sync_window = edtSegSyncWindow->Text.ToDouble();
	WCRun->log_window = edtLogWindow->Text.ToDouble();
	WCRun->log_pixels = log_pixels;
	if (cbShifting->State == cbChecked) WCRun->shifting=true;
	else WCRun->shifting=false;
	WCRun->clock_start = clock();
	WCRun->clock_end = clock();
	WCRun->M=Image1->Picture->Width;
	WCRun->N=Image1->Picture->Height;
	WCRun->image = CreateDoubleArray(WCRun->M+2,WCRun->N+2,4);
	int c;
	for(int i=0;i<=Image1->Picture->Width;i++)
	{
		for(int j=0;j<=Image1->Picture->Height;j++)
		{
			c = Image1->Picture->Bitmap->Canvas->Pixels[i][j];
			WCRun->image[i+1][j+1][0]=((c%256)+((c/256)%256)+((c/65536)%256))/3;
			WCRun->image[i+1][j+1][1]=(c/65536)%256;
			WCRun->image[i+1][j+1][2]=(c/256)%256;
			WCRun->image[i+1][j+1][3]=c%256;
		}
	}
	WCRun->Resume();
	Timer1->Enabled = true;
	btnRun->Enabled = false;
	btnLoadImage->Enabled = false;
	btnSetLogPixels->Enabled = false;
	btnCancel->Enabled = true;
	lblSegmentationDone->Visible = false;
	lblSegObj->Caption = "0";

}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnCancelClick(TObject *Sender)
{
	WCRun->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WCRunHandleTerminate(TObject *Sender)
{
	Timer1->Enabled=false;
	UpdateLabels();
	btnCancel->Enabled=false;
	btnRun->Enabled=true;
	btnLoadImage->Enabled=true;
	btnSetLogPixels->Enabled=true;
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	UpdateLabels();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::cbLoggingClick(TObject *Sender)
{
	if (cbLogging->Checked) edtt_record->Enabled = True;
	else edtt_record->Enabled = False;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::btnLoadImageClick(TObject *Sender)
{
	if (OpenPictureDialog1->Execute())
	{
		DestroyArray(log_pixels,Image1->Picture->Width+1,Image1->Picture->Height+1);
		Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
		ImageSegmented->Picture->LoadFromFile(OpenPictureDialog1->FileName);
		frmLogPixels->ImageLogPixels->Picture->LoadFromFile(OpenPictureDialog1->FileName);
		ImageSegmented->Picture->Bitmap->Monochrome = false;
		frmLogPixels->ImageLogPixels->Picture->Bitmap->Monochrome=false;
		lblSize->Caption = String(Image1->Picture->Width) + " x " + String(Image1->Picture->Height);
		frmLogPixels->StringGrid1->RowCount=1;
		frmLogPixels->EditClass->Text=0;
		log_pixels = CreateIntArray(Image1->Picture->Width+1,Image1->Picture->Height+1);
		for(int i=0;i<Form1->Image1->Picture->Width;i++)
			for(int j=0;j<Form1->Image1->Picture->Height;j++)
				log_pixels[i][j]=-1;
		frmLogPixels->LabelSelectedPoints->Caption = 0;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnSetLogPixelsClick(TObject *Sender)
{
	frmLogPixels->ShowModal();
	cbLogging->Checked=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
	log_pixels = CreateIntArray(Image1->Picture->Width+1,Image1->Picture->Height+1);
	for(int i=0;i<Form1->Image1->Picture->Width;i++)
		for(int j=0;j<Form1->Image1->Picture->Height;j++)
			log_pixels[i][j]=-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBoxStopLoggingTimeClick(TObject *Sender)
{
	if (CheckBoxStopLoggingTime->Checked) EditStopLoggingTime->Enabled = True;
	else EditStopLoggingTime->Enabled = False;

}
//---------------------------------------------------------------------------




void __fastcall TForm1::ButtonSaveImageClick(TObject *Sender)
{
	if(SavePictureDialog1->Execute())
	{
		ImageSegmented->Picture->SaveToFile(SavePictureDialog1->FileName);
	}
}
//---------------------------------------------------------------------------


