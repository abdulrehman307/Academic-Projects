Include Irvine32.inc
Include macros.inc
Max_cars = 20
Noplate_Len = 16
Contact_Len = 12
Time_Len = 8
Slot_Len = 4
Car_Size = 48

.data
menustr BYTE 0Dh,0Ah,
"===== CAR PARKING SYSTEM =====",0Dh,0Ah,
"1. ADD CAR",0Dh,0Ah,
"2. EXIT CAR",0Dh,0Ah,
"3. DISPLAY CARS",0Dh,0Ah,
"4. SEARCH CAR",0Dh,0Ah,
"5. SAVE TO FILE",0Dh,0Ah,
"6. LOAD FROM FILE",0Dh,0Ah,
"7. CLEAR BUFFER ",0Dh,0Ah,
"0. EXIT",0Dh,0Ah,
"ENTER YOUR CHOICE: ",0

Cars Byte Max_cars * Car_Size Dup(0)
carcount dword 0

NoplateBuf Byte Noplate_Len Dup(0)
ContactBuf Byte Contact_Len Dup(0)
inTimeBuf Byte Time_Len Dup(0)
outTimeBuf Byte Time_Len Dup(0)
SlotNo Dword ?

filename Byte "Cars.txt",0
filehandle Handle ?

strFull Byte "Parking Slots are Full!",0
strEmpty Byte "No Cars Parked! ",0
strFound Byte "Car Found!",0
strNotfound Byte "Car Not Found!",0
.code
main Proc

MainLoop:
call MainMenu
cmp eax,0
je ExitProgram
cmp eax,1
je A1
cmp eax,2
je A2
cmp eax,3
je A3
cmp eax,4
je A4
cmp eax,5
je A5
cmp eax, 6
je A6
cmp eax,7
je A7
jmp MainLoop


A1:
call Addcar
jmp MainLoop
A2:
call Removecar
jmp MainLoop
A3:
call Displaycars
jmp MainLoop
A4:
call Searchcar
jmp MainLoop
A5:
call Savetofile 
jmp MainLoop
A6:
call Loadfromfile
jmp MainLoop
A7:
call ClearBuffer
jmp MainLoop

Exitprogram:
exit
Main Endp

;Main Menu Procedure
MainMenu Proc
mov edx, offset menustr
call writestring
call readint
ret
MainMenu Endp

;Add Procedure
Addcar Proc
cmp carcount, Max_cars
jae Full

call clearbuffer
mWrite "Enter Car Number :"
mov edx, offset NoplateBuf
mov ecx, Noplate_Len
call readstring

mWrite "Enter Contact No :"
mov edx , Offset ContactBuf
mov ecx , Contact_Len
call readstring

mWrite "Enter Parking Slot :"
call readint
mov SlotNo,eax

mWrite "Enter In Time (HH:MM) :"
mov edx, offset inTimeBuf
mov ecx, Time_Len
call readstring

mov esi, carcount
imul esi,Car_Size
mov edi, offset cars
add edi, esi
;No Plate copy data
mov esi,offset NoplateBuf
mov ecx, Noplate_Len
rep movsb
;Contact copy data
mov esi,offset ContactBuf
mov ecx, Contact_Len
rep movsb
;Slot copy data
mov eax, SlotNo
stosd

;In Time copy data
mov esi,offset inTimeBuf
mov ecx, Time_Len
rep movsb
mwrite "Car Successfully Added! "
inc carcount
ret
Full:
mov edx,offset strFull
call writestring
call crlf
ret
Addcar Endp

;Remove Car
RemoveCar Proc
cmp carcount,0
je Empty

call clearbuffer
mWrite "Enter Number Plate To Remove :"
mov edx, offset NoplateBuf
mov ecx, Noplate_Len
call readstring
mov esi,0
Find:
cmp esi,carcount
je Notfound
mov edi, offset cars
mov eax, esi
imul eax, Car_Size
add edi,eax
push esi
mov esi, Offset NoplateBuf
mov ecx, Noplate_Len
repe cmpsb
pop esi
je Found

inc esi
jmp Find

Found:
mWrite "Enter Out Time :"
mov edx , offset outTimeBuf
mov ecx, Time_Len
call readstring
mov edi, offset cars
mov eax,esi
imul eax, Car_Size
add edi,eax
add edi, Noplate_Len + Contact_Len + Slot_Len + Time_Len
mov esi ,offset outTimeBuf
mov ecx, Time_Len
rep movsb
mwrite "Car successfully Exited!"
dec carCount
ret
Notfound:
mov edx,offset strNotfound
call writestring
call crlf
ret
Empty:
mov edx, offset strEmpty
call writestring
call crlf
ret
RemoveCar Endp

;Display Cars
DisplayCars proc
cmp carcount, 0
je Empty
mov esi,0
DisplayLoop:
cmp esi,carcount
je Done
mov edi, offset cars
mov eax,esi
imul eax, Car_Size
add edi,eax

mWrite " Number Plate: "
mov edx,edi
call writestring
call crlf
add edi, Noplate_Len

mWrite "Contact :"
mov edx,edi
call writestring
call crlf
add edi, Contact_Len
mWrite "Slot :"
mov eax, [edi]
call writeint
call crlf

add edi, Slot_Len
mWrite "In Time :"
mov edx, edi
call writestring
call crlf
 
 call crlf
 inc esi
 jmp DisplayLoop
 Empty:
mov edx, offset strEmpty
call writestring
call crlf
ret

 Done:
 ret
 DisplayCars Endp
 
 ;Search Car Procedure
 SearchCar PROC
    cmp carcount, 0
    je SearchEmpty

    call ClearBuffer
    mWrite "Enter Plate to Search: "
    mov edx, offset NoplateBuf
    mov ecx, Noplate_Len
    call ReadString

    mov esi, 0                      ; index = 0

SearchLoop:
    cmp esi, carcount
    je SearchNotFound

    ; -------- calculate record base address --------
    mov eax, esi
    imul eax, Car_Size
    mov ebx, offset cars
    add ebx, eax                    ; EBX = record base

    ; -------- compare plate numbers --------
    push esi
    mov edi, ebx                    ; plate starts at record base
    mov esi, offset NoplateBuf
    mov ecx, NoPlate_Len
    repe cmpsb
    pop esi
    je SearchFound

    inc esi
    jmp SearchLoop

SearchFound:
    call Crlf
    mWrite "Car Found!"
    call Crlf

    ; -------- Plate --------
    mWrite " Number Plate: "
    mov edx, ebx
    call WriteString
    call Crlf

    ; -------- Contact --------
    mWrite "Contact: "
    mov edx, ebx
    add edx, NoPlate_Len
    call WriteString
    call Crlf

    ; -------- Slot --------
    mWrite "Slot: "
    mov eax, [ebx + Noplate_Len + Contact_Len]
    call WriteInt
    call Crlf

    ; -------- In Time --------
    mWrite "In Time: "
    mov edx, ebx
    add edx, Noplate_Len + Contact_Len + Slot_Len
    call WriteString
    call Crlf

    ret

SearchNotFound:
    mWrite "Car Not Found!"
    call Crlf
    ret

SearchEmpty:
    mWrite "Parking is Empty!"
    call Crlf
    ret
SearchCar ENDP



    ;Save To File
    SaveToFile PROC
    mov edx, Offset fileName
    call CreateOutputFile
    mov fileHandle, eax

    mov eax, fileHandle
    mov edx, offset cars
    mov ecx, carcount
    imul ecx, Car_Size
    call WriteToFile

    mov eax, fileHandle
    call CloseFile

    mWrite "Data Saved Successfully!"
    call Crlf
    ret
SaveToFile ENDP

    ;Load Data From file

  LoadFromFile PROC

    ;  open file
    mov edx, OFFSET fileName
    call OpenInputFile
    jc LoadFail                 

    mov fileHandle, eax       

    ; read file data
    mov eax, fileHandle
    mov edx, OFFSET cars
    mov ecx, Max_cars * Car_Size
    call ReadFromFile            ; eax = bytesRead

    ;calculate carcount
    cmp eax, 0
    je NoData                    

    mov ebx, Car_Size          
    xor edx, edx
    div ebx       
    mov carCount, eax

    ; close file
    mov eax, fileHandle
    call CloseFile
    mWrite "Data Loaded Successfully!"
    call Crlf
    call Crlf

    call DisplayCars

    ret

LoadFail:
    mWrite "No Previous Data Found!"
    call Crlf
    ret

; empty file
NoData:
    mov eax, fileHandle
    call CloseFile
    mWrite "File is empty!"
    call Crlf
    ret

LoadFromFile ENDP


    ;Clear Buffer 
 ClearBuffer Proc
    mov ecx, Noplate_Len
    mov edi, offset NoplateBuf
    mov al, 0
    rep stosb

    mov ecx, Contact_Len
    mov edi, offset ContactBuf
    rep stosb

    mov ecx, Time_Len
    mov edi, offset inTimeBuf
    rep stosb

    mov ecx, Time_Len
    mov edi, Offset outTimeBuf
    rep stosb
    mwrite "All Buffers Cleared!"

    ret
    
ClearBuffer ENDP
 END main


